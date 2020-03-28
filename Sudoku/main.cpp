#include <cstdio>
#include <map>
#include <string>
#include <vector>

#pragma warning(disable:4996)
#pragma warning(disable:26451)

using Map = std::vector<int>;

bool Exists(const Map& map, const int m, const int n, const int x, const int y)
{
	for (int i = 0; i < m; ++i)
	{
		if (map[y * m + i] == n || map[i * m + x] == n)
		{
			return true;
		}
	}

	int startX = 0;
	int startY = 0;

	switch (m)
	{
	case 4:
		startX = x / 2 * 2;
		startY = y / 2 * 2;

		for (int i = startX; i < startX + 2; ++i)
		{
			for (int j = startY; j < startY + 2; ++j)
			{
				if (map[j * 4 + i] == n)
				{
					return true;
				}
			}
		}
		break;
	case 6:
		startX = x / 3 * 3;
		startY = y / 2 * 2;

		for (int i = startX; i < startX + 3; ++i)
		{
			for (int j = startY; j < startY + 2; ++j)
			{
				if (map[j * 6 + i] == n)
				{
					return true;
				}
			}
		}
		break;
	case 8:
		startX = x / 2 * 2;
		startY = y / 4 * 4;

		for (int i = startX; i < startX + 2; ++i)
		{
			for (int j = startY; j < startY + 4; ++j)
			{
				if (map[j * 8 + i] == n)
				{
					return true;
				}
			}
		}
		break;
	case 9:
		startX = x / 3 * 3;
		startY = y / 3 * 3;

		for (int i = startX; i < startX + 3; ++i)
		{
			for (int j = startY; j < startY + 3; ++j)
			{
				if (map[j * 9 + i] == n)
				{
					return true;
				}
			}
		}
		break;
	default:;
	}
	return false;
}

void PlaceNumber(Map& map, int m, int i)
{
	if (i >= m * m)
	{
		throw std::exception("Finished!");
	}
	if (map[i] > 0)
	{
		PlaceNumber(map, m, i + 1);
		return;
	}
	for (int n = 1; n <= m; ++n)
	{
		if (!Exists(map, m, n, i % m, i / m))
		{
			map[i] = n;
			PlaceNumber(map, m, i + 1);
			map[i] = 0;
		}
	}
}

bool Solve(Map& map, int m)
{
	try
	{
		PlaceNumber(map, m, 0);
		return false;
	}
	catch (std::exception&)
	{
		return true;
	}
}

void Parse(int argc, char* argv[] ,int& m, int& n, std::string& input, std::string& output)
{
	std::map<std::string, std::string> param{};

	for (int i = 1; i < argc; i += 2)
	{
		param.insert(std::make_pair(argv[i], argv[i + 1]));
	}

	if (param.find("-m") != param.end())
	{
		m = std::stoi(param["-m"]);
	}
	else
	{
		throw std::exception("缺m");
	}

	if (param.find("-n") != param.end())
	{
		n = std::stoi(param["-n"]);
	}
	else
	{
		throw std::exception("缺n");
	}

	if (param.find("-i") != param.end())
	{
		input = param["-i"];
	}
	else
	{
		throw std::exception("缺i");
	}

	if (param.find("-o") != param.end())
	{
		output = param["-o"];
	}
	else
	{
		throw std::exception("缺o");
	}
}

int main_(int argc, char* argv[])
{
	if (argc != 9)
	{
		fprintf(stderr, "?????????\n  %s -m 盘面阶数 -n 盘面数量 -i 输入文件名 -o 输出文件名\n", argv[0]);
		return 1;
	}
	try
	{
		int m, n;
		std::string input, output;

		Parse(argc, argv, m, n, input, output);

		auto ifp = fopen(input.c_str(), "r");
		if (ifp == nullptr)
		{
			throw std::exception("open input file failed");
		}

		auto ofp = fopen(output.c_str(), "w");
		if (ofp == nullptr)
		{
			throw std::exception("open output file failed");
		}

		Map map(m * m, 0);

		for (int i = 0; i < n; ++i)
		{
			for (int pos = 0; pos < m * m; ++pos)
			{
				if(fscanf(ifp, "%d", &map[pos]) == EOF)
				{
					throw std::exception("size no match");
				}
			}

			if (Solve(map, m))
			{
				for (int i = 0; i < map.size(); ++i)
				{
					fprintf(ofp, "%d", map[i]);
					if ((i + 1) % m == 0)
					{
						fprintf(ofp, "\n");
					}
					else
					{
						fprintf(ofp, " ");
					}
				}
			}
			else
			{
				fprintf(ofp, "......\n");
			}
			fprintf(ofp, "\n");
		}

		fclose(ifp);
		fclose(ofp);
	}
	catch (std::exception & exception)
	{
		fprintf(stderr, "%s\n", exception.what());
		return 1;
	}
	return 0;
}


int main(int argc, char* argv[])
{
	return main_(argc, argv);
}
