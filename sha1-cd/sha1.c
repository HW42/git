#include "sha1.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

void sha1_cd_init(SHA1_CTX *ctx) {
    SHA1DCInit(ctx);
    SHA1DCSetDetectReducedRoundCollision(ctx, 1);
}

void sha1_cd_update(SHA1_CTX *ctx, const void *data_in, unsigned long len) {
    while (len > 0) {
        unsigned long n = len;
        if (n > UINT_MAX) {
            n = UINT_MAX;
        }
        SHA1DCUpdate(ctx, (const char *) data_in, (unsigned) n);
        len -= n;
        data_in += n;
    }
}

void sha1_cd_final(unsigned char hash_out[20], SHA1_CTX *ctx) {
    if (SHA1DCFinal(hash_out, ctx)) {
       fprintf(stderr, "ERROR: SHA1 collision deteced! Aborting.\n");
       exit(127);
    }
}
