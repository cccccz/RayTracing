#include "camera.h"

static unsigned long __stdcall doRender(void* vdata)
{
#define TILESIZE 16

    // prep data
    TData* data = (TData*)vdata;
    const int width = data->iw;
    const int height = data->ih;

    const int   numxtiles = width / TILESIZE;
    const int   numytiles = height / TILESIZE;
    const int   numtiles = numxtiles * numytiles;
    //const hittable& world = data->world;

    // synch point
    WaitForSingleObject(data->barrier, 0);

    // render tiles
    for (;;)
    {
        // get next tile to consume
        const int tile = InterlockedIncrement(&data->tileID) - 1;
        if (tile >= numtiles) break;

        // tile offset
        const int ia = TILESIZE * (tile % numxtiles);
        const int ja = TILESIZE * (tile / numxtiles);

        // for every pixel in this tile, compute color
        for (int j = 0; j < TILESIZE; j++)
            for (int i = 0; i < TILESIZE; i++)
                data->framebuffer->at(width * (ja + j) + (ia + i)) = data->cam->compute_color(
                    ia + i, ja + j, data->world);
    }

    // synch point
    ReleaseSemaphore(data->barrier, 1, NULL);

    return 1;
}
