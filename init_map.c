#include "so_long.h"

t_tile **ft_tilemap_alloc(t_tile **tilemap, char *map)
{
    int y = 1;
    int x = 0;
    int i = 0;

    while(map[i])
    {   
        if(y == 1)
            x++;
        if(map[i] == '\n' && map[i+1] != '\0')
                y++;        
        i++;
    }

    tilemap = malloc(sizeof (t_tile) * (x + 1) * (y + 1));

    return(tilemap)
}

void    ft_init_map(t_tile **tilemap, char *map)
{
    int x = 0;
    int y = 0;
    int i = 0;
    int xbuff = 0;
    int ybuff = 0;
    
    while(map[i])
    {
        if(map[i] == '\n')
        {
            ybuff += SIZE;
            y++;
            xbuff = 0;
            x = 0;                       
        } 

        tilemap[x][y].position.x = xbuff;
        tilemap[x][y].position.y = ybuff;
        tilemap[x][y].type = map[i];
        xbuff += SIZE;
        x++;               
        i++;
    }
}