#include "so_long.h"

t_tile **ft_tilemap_alloc(char *map)
{
    t_tile **tilemap;
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

    tilemap = malloc(sizeof(t_tile *) * (y + 1));
    tilemap[y] = '\0';
    while (y--)
    {
        tilemap[y]= malloc(sizeof(t_tile) * x);
    }
    

    return(tilemap);
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

        tilemap[y][x].position.x = xbuff;
        tilemap[y][x].position.y = ybuff;
        tilemap[y][x].type = map[i];
        xbuff += SIZE;
        x++;               
        i++;
    }
}