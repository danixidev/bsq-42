#include <stdio.h>
#include <unistd.h>

int *convert_to_array(const char *nombreArchivo);

struct Area {
	int position;
	int size;
};

struct Map {
	int *map;
	int rows;
	int cols;
};


int	area_has_block(struct Map map, struct Area area)
{
	int index;
	int	position;

	index = 0;
	position = 0;
	while(index < (map.cols * area.size))
	{
		if(position < area.size)
		{
			if(map.map[index] == 1)
				return (1);
			position++;
			index++;
		}
		else
		{
			index += (map.cols - area.size);
			position = 0;
		}
	}

	return (0);
}

int	max_area_pos(struct Map map, int pos)
{
	int size;
	struct Area area;

	size = 0;
	area.position = pos;
	while(size < map.cols || size < map.rows)
	{
		area.size = size + 1;
		if(area_has_block(map, area))
			break;
		size++;
	}


	// area.position = pos;
	// area.size = 3;
	// area_has_block(map, area);

	return (size);
}

void	solve(struct Map map)
{
	int	index;
	int size;
	struct Area area;
	struct Area max_area;

	// index = 0;
	// while (index < (map.rows * map.cols))
	// {
	// 	size = max_area_pos(map, index);

	// 	printf("pos: %d\nsize: %d\n\n", index, size);
	// 	// if(size > max_area.size)
	// 	// {
	// 	// 	max_area.size = size;
	// 	// 	max_area.position = index;
	// 	// }
	// 	index++;
	// }

	// printf("pos: %d\nsize: %d", max_area.position, max_area.size);
	area.position = 0;
	area.size = 5;
	printf("%d", area_has_block(map, area));
}

int main()
{
	struct Map mapa;
	int *map;

	mapa.rows = 9;
	mapa.cols = 27;
	map = convert_to_array("basic_map.txt");
	mapa.map = map;

	// int index = 0;
	// int count = 0;
	// char c;
	// while (index < 243)
	// {
	// 	if(count == 27)
	// 	{
	// 		count = 0;
	// 		write(1, "\n", 1);
	// 	}
	// 	c = map[index] + '0';
	// 	write(1, &c, 1);
	// 	index++;
	// 	count++;
	// }
	solve(mapa);
}