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
	int max_cols;
	int max_rows;

	max_cols = map.cols - (area.position % map.cols);
	max_rows = map.rows - (area.position / map.cols);
	index = area.position;
	position = 0;
	if(map.map[index] == 1)
		return (1);
	while(index < area.position + (map.cols * area.size))
	{
		if(position < area.size)
		{
			if(map.map[index] == 1 || area.size > max_cols || area.size > max_rows)
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
	while(size < (map.cols - (pos % map.cols)) || size < (map.rows / map.rows))
	{
		area.size = size + 1;
		area.position = pos;
		if(area_has_block(map, area))
			break;
		size++;
	}
	return (size);
}

void paint_solution(struct Map map, struct Area area)
{
	int index;
	char c;

	index = 0;
	while (index < (map.cols * map.rows))
	{
		if(index % map.cols == 0 && index != 0)
			write(1, "\n", 1);
		c = map.map[index] + '0';

		if(map.map[index] == 0)
		{
			//Logica para pintar X
			write(1, ".", 1);
		}
		else if(map.map[index] == 1)
			write(1, "o", 1);
		index++;
	}
}

void	solve(struct Map map)
{
	int	index;
	int size;
	struct Area area;
	struct Area max_area;
	int max_size;
	int	max_pos;

	index = 0;
	max_size = 0;
	while (index < (map.rows * map.cols))
	{
		size = max_area_pos(map, index);

		if(size > max_size)
		{
			max_size = size;
			max_pos = index;
			// max_area.size = size;
			// max_area.position = index;
		}
		index++;
	}
	printf("pos: %d\nsize: %d\n\n", max_pos, max_size);

	// paint_solution(map, max_area);

	// printf("%d %d", max_area.size, max_area.position);

	// area.position = 16;
	// area.size = 7;
	// printf("%d", area_has_block(map, area));

	// printf("%d", max_area_pos(map, 300));
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