#include <stdlib.h>

#include <cache/cache.h>

#include <vcc_if.h>

VCL_STRING
vmod_randomstr(VRT_CTX, VCL_INT n, VCL_STRING seed)
{
    char *p;
    size_t len;
    CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
    CHECK_OBJ_NOTNULL(ctx->ws, WS_MAGIC);
	if (seed == NULL)
		return (NULL);

    len = n;

    if (len >= WS_ReserveSize(ctx->ws, len + 1)) {
		WS_Release(ctx->ws, 0);
		return (NULL);
	}
    p = ctx->ws->f;
    while(n) {
        p[len - n] = 'a';
        n--;
    }
    p[len] = '\0';
    WS_Release(ctx->ws, len + 1);
    return (p);
}
