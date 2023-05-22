#include <stdlib.h>
#include <string.h>
#include <cache/cache.h>

#include <vcc_if.h>

// Robert Jenkins' 96 bit Mix Function
unsigned long mix(unsigned long a, unsigned long b, unsigned long c)
{
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}

int
vmod_event(VRT_CTX, struct vmod_priv *priv, enum vcl_event_e e)
{
    (void)ctx;
	(void)priv;
    switch (e) {
    case VCL_EVENT_LOAD:
        unsigned long seed = mix(clock(), time(NULL), getpid());
        srand(seed);
        break
	default:
		break;
	}
	return (0);
}

VCL_STRING
vmod_randomstr(VRT_CTX, VCL_INT n, VCL_STRING seed)
{
    char *p;
    size_t len, seed_count;
    CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
    CHECK_OBJ_NOTNULL(ctx->ws, WS_MAGIC);
	if (seed == NULL)
		return (NULL);

    seed_count = strlen(seed);
    if (seed_count == 0)
        return (NULL);

    len = n;

    if (len >= WS_ReserveSize(ctx->ws, len + 1)) {
		WS_Release(ctx->ws, 0);
		return (NULL);
	}
    p = ctx->ws->f;
    while(n) {
        p[len - n] = seed[rand() % seed_count];
        n--;
    }
    p[len] = '\0';
    WS_Release(ctx->ws, len + 1);
    return (p);
}
