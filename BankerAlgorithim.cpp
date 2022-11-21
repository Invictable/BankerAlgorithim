#include <iostream>
#include <fstream>
using std::cerr;
using std::ifstream;

int main()
{
	bool debug = false; // shows matrices as they build and end result checking

	int n; // Process Count
	int m; // Resource Count

	std::fstream data;
	data.open("data.txt"); // Open data.txt

	if (!data.is_open())
	{
		std::cout << "File failed to load.";
		return 1;
	}

	data >> n >> m;

	int allocMatrix[n][m] = {}; // Establish a matrix holding Required Allocation for each process

	int in = 0;
	int a, b, c;
	while (data >> a >> b >> c)
	{
		allocMatrix[in][0] = a;
		allocMatrix[in][1] = b;
		allocMatrix[in][2] = c;

		in++;
		if (in == n)
		{
			break;
		}
	}

	int maxMatrix[n][m] = {}; // Establish a matrix holding the Max values for each process
	in = 0;
	while (data >> a >> b >> c)
	{
		maxMatrix[in][0] = a;
		maxMatrix[in][1] = b;
		maxMatrix[in][2] = c;

		in++;
		if (in == n)
		{
			break;
		}
	}

	int resourceMatrix[m] = {}; // Establish a matrix holding the avaliable resources 
	data >> a >> b >> c;
	resourceMatrix[0] = a;
	resourceMatrix[1] = b;
	resourceMatrix[2] = c;

	data.close();

	if (debug) // previews matrices so we can see they loaded correctly
	{
		std::cout << "Process Count: " << n << std::endl;
		std::cout << "Resource Count: " << m << std::endl;
		for (int i = 0; i < n; i++)
		{
			for (int ii = 0; ii < m; ii++)
			{
				std::cout << allocMatrix[i][ii];
			}
			std::cout << " ";
		}
		std::cout << std::endl;
		for (int i = 0; i < n; i++)
		{
			for (int ii = 0; ii < m; ii++)
			{
				std::cout << maxMatrix[i][ii];
			}
			std::cout << " ";
		}
		std::cout << std::endl;
		std::cout << resourceMatrix[0];
		std::cout << resourceMatrix[1];
		std::cout << resourceMatrix[2];
	}

	in = 0; // corresponds to matrix columns
	int im = 0; // corresponds to matrix rows
	bool procede;

	int sequence[n]; // Holds sequence as its found
	int processCount = 0; // Holds which process is being evaluated

	int check[n];
	for (int i = 0; i < n; i++)
	{
		check[i] = 0;
	}

	for (int i = 0; i < n; i++) // tests through possible outcomes
	{
		for (in = 0; in < n; in++)
		{
			if (check[in] == 0)
			{
				procede = true;
				for (im = 0; im < m; im++) 
				{
					if (maxMatrix[in][im] - allocMatrix[in][im] > resourceMatrix[im])
					{
						procede = false;
						break;
					}
				}

				if (procede)
				{
					sequence[processCount] = in;
					processCount++;
					for (int y = 0; y < m; y++)
					{
						resourceMatrix[y] += allocMatrix[in][y];
					}
					check[in] = 1;
				}
			}
		}
	}

	bool safe = true;
	for (int i = 0; i < n; i++) // checks if sequence was registered as unsafe anywhere
	{
		if(debug)
			std::cout << check[i];

		if (check[i] == 0)
		{
			std::cout << "The sequence is not safe.";
			safe = false;
			break;
		}
	}

	if (safe) // completion display
	{
		std::cout << "\nSafe Sequence found:" << std::endl;
		for (int i = 0; i < n; i++)
		{
			std::cout << "p" << sequence[i];
			if (i < n - 1)
				std::cout << " --> ";
		}
	}

	return 0;
}
