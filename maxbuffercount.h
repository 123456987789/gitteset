#ifndef __MAX_BUFFER_COUNT__
#define __MAX_BUFFER_COUNT__

int get_maxbuffercount();

static const int MAX_BUFFER_COUNT = get_maxbuffercount();

int get_maxbuffercount()
{
    int maxbuffercount = 10;
    char *str_maxbuffercount = nullptr;
    str_maxbuffercount = getenv("MAX_BUFFER_COUNT");
    if(str_maxbuffercount)
        maxbuffercount = atoi(str_maxbuffercount);
    return maxbuffercount;
}

#endif