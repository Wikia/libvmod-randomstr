#include <stdlib.h>

#include <cache/cache.h>

#include <vcc_if.h>

VCL_STRING
vmod_randomstr(VRT_CTX, VCL_INT n, VCL_STRING s2)
{
    char *p;
    size_t len;
    len = n;
    CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);

    if (len >= WS_ReserveSize(ctx->ws, len + 1)) {
		WS_Release(ctx->ws, 0);
		return (NULL);
	}
    while(n) {
        p[len - n] = 'a';
        n--;
    }
    p[len] = '\0';
    WS_Release(ctx->ws, len + 1);
    return (p);
}
