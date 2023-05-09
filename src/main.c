#include <zephyr.h>
#include <stdio.h>
#include <string.h>
#include "ubx_parser.h"

int main(void) {
    // Sample data
    uint8_t data[] = {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
                      0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00};

    struct ubx_nav_timels timels;

    parse_ubx_nav_timels(data, sizeof(data), &timels);

    printf("srcOfCurrLs: %d\n", timels.srcOfCurrLs);

    return 0;
}
