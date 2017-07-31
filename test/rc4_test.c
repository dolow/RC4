//  rc4_test.c
//
//  Created by Smith on 2017/07/31.
//  Copyright © 2017 Smith. All rights reserved.

#include "rc4.h"

#include <stdlib.h>
#include <stdio.h>

// TODO: gtest or ctest
// TODO: look for example vector and test for it
int main(int argc, const char** argv)
{
    unsigned char user_key[16] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };

    unsigned char pt[23] = {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
        0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16
    };
    unsigned char ct[23];
    
    {
        unsigned char encrypt_key[RC4_TABLE_LENGTH];
        rc4_generate_key(encrypt_key, user_key, 16);

        rc4_encrypt(encrypt_key, pt, ct, 23);
        for (int i = 0; i < 23; i++) printf("%02x ", ct[i]); printf("\n");
    }
    {
        unsigned char dt[23];

        unsigned char decrypt_key[RC4_TABLE_LENGTH];
        rc4_generate_key(decrypt_key, user_key, 16);

        rc4_decrypt(decrypt_key, ct, dt, 23);
        for (int i = 0; i < 23; i++) printf("%02x ", dt[i]); printf("\n");
    }

    return 0;
}
