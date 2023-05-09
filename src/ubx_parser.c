#include <string.h>
#include "ubx_parser.h"

void parse_ubx_nav_timels(uint8_t *data, size_t len, struct ubx_nav_timels *timels) {
    if (len < sizeof(struct ubx_nav_timels)) {
        printf("Invalid data length\n");
        return;
    }

    memcpy(timels, data, sizeof(struct ubx_nav_timels));
}
