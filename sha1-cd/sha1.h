#include "sha1collisiondetection/lib/sha1.h"

void sha1_cd_init(SHA1_CTX *ctx);
void sha1_cd_update(SHA1_CTX *ctx, const void *data_in, unsigned long len);
void sha1_cd_final(unsigned char hash_out[20], SHA1_CTX *ctx);

#define platform_SHA_CTX        SHA1_CTX
#define platform_SHA1_Init      sha1_cd_init
#define platform_SHA1_Update    sha1_cd_update
#define platform_SHA1_Final     sha1_cd_final
