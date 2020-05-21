#include<stdio.h>
#define X_SIZE 200
#define Y_SIZE 700
#define Z_SIZE 200
 
// x: 9.95 -> 11.95 => 200
// y: -3 -> -9.75 => 700  
// z: 3.9 -> 5.9 => 200
//-> 3 * 10 x y z
// float mapping to int
// x' = (x - 9.95) * 100; -> inverse x = x' / 100 + 9.95   
// y' = -( (y + 3) * 100 ); -> inverse y = -(y' / 100 - 3) 
// z' = ( z - 3.9 ) * 100 ;  -> inverse  z = z' / 100 + 3.9

int min_index[9][3];
int max_index[9][3];
//-> 3 * 10 x y z 
double min[9][3] = {{10.75, -4.9, 4.8},
					 {10.75, -6.5, 3.9},
					 {9.95, -7.2, 3.9},
					 {10.10, -8.6, 5.4},
					 {11.45, -9.0, 4.1},
					 {9.95, -9.1, 4.6},
					 {10.95, -8.4, 4.9},
					 {11.05, -8.9, 4.2},
					 {10.45, -9.1, 4.6}};
					 
double max[9][3] = {{10.95, -4.7, 5.0},
					 {11.95, -6.4, 5.9},
					 {10.85, -7.1, 5.9},
					 {11.1, -8.3, 5.9},
					 {11.95, -8.5, 5.1},
					 {10.45, -8.6, 5.6},
					 {11.15, -8.2, 5.1},
					 {11.25, -8.7, 4.4},
					 {10.65, -8.9, 4.8}};
					 
int data[X_SIZE][Y_SIZE][Z_SIZE];
int main()
{
	for(int i = 0; i < 9; i++)
	{
		min_index[i][0] = int((min[i][0] - 9.95) * 100);
		min_index[i][1] = int(- ((min[i][1] + 3) * 100));
		min_index[i][2] = int((min[i][2] - 3.9) * 100);
		max_index[i][0] = int((max[i][0] - 9.95) * 100);
		max_index[i][1] = int(- ((max[i][1] + 3) * 100));
		max_index[i][2] = int((max[i][2] - 3.9) * 100);
		 
	}
	for(int i = 0; i < X_SIZE; i++)
		for(int j = 0; j < Y_SIZE; j ++)
			for(int k = 0; k < Z_SIZE; k++)
				data[i][j][k] = 0;
				
	for(int index = 0; index < 9; index++)
	{
		for(int i = min_index[index][0]; i <= max_index[index][0]; i++)
			for(int j = min_index[index][1]; j <= max_index[index][1]; j++)
				for(int k = min_index[index][2]; k <= max_index[index][2]; k++)
					data[i][j][k] = 1;
	}	
} 