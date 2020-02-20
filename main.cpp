/// <summary>
/// Google Hash Code Qualification
/// @Author Michael Rainsford Ryan & Ben Millar
/// @Date 20/02/2020
/// </summary>


#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <algorithm>

/////////////////////////////////////////////////////////////////
struct Library
{
	int m_numBooks = 0;
	int m_daysToSignUp = 0;
	int m_booksPerDay = 0;
	std::vector<int> m_bookIDs;
};


/////////////////////////////////////////////////////////////////
struct InputData
{
	int m_totalBooks = 0;
	int m_numLibraries = 0;
	int m_numDays = 0;
	std::vector<int> m_bookScores;
	std::vector<Library> m_libraries;
};


/////////////////////////////////////////////////////////////////
struct OutputLibrary
{
	int m_libIndex = 0;
	int m_booksSent = 0;
	std::vector<int> m_sentBookIndices;
};

/////////////////////////////////////////////////////////////////
struct OutputData
{
	int m_numLibsSignedUp = 0;
	std::vector<OutputLibrary> m_libraries;
};


/////////////////////////////////////////////////////////////////

const InputData getInputData(const std::string t_name);
OutputData getSolutionData(const InputData t_inputData);
OutputData getSolutionData1(const InputData t_inputData);
void writeToFile(OutputData t_outputData, const std::string t_name);

std::vector<int> getHighestFirst(Library& t_lib, std::vector<int>& t_bookScores);
std::vector<int> getShortestSetup(std::vector<Library>& t_libraries);

int main()
{
	std::string fileName = "a_example";
	InputData inputData = getInputData(fileName);

	// Sort libraries by shortest setup time
	std::vector<int> libPriorities{ getShortestSetup(inputData.m_libraries) };

	// Sort their books by highest value
	for (int i : libPriorities)
	{
		std::vector<int> mostValuableBooks = getHighestFirst(inputData.m_libraries.at(i), inputData.m_bookScores);
	}

	OutputData outputData;
	outputData.m_numLibsSignedUp = 2;

	OutputLibrary lib;
	lib.m_libIndex = 1;
	lib.m_booksSent = 3;
	lib.m_sentBookIndices.push_back(5);
	lib.m_sentBookIndices.push_back(2);
	lib.m_sentBookIndices.push_back(3);

	outputData.m_libraries.push_back(lib);

	lib.m_sentBookIndices.clear();

	lib.m_libIndex = 0;
	lib.m_booksSent = 5;
	lib.m_sentBookIndices.push_back(0);
	lib.m_sentBookIndices.push_back(1);
	lib.m_sentBookIndices.push_back(2);
	lib.m_sentBookIndices.push_back(3);
	lib.m_sentBookIndices.push_back(4);

	outputData.m_libraries.push_back(lib);

	writeToFile(outputData, fileName);

	system("pause");
	return EXIT_SUCCESS;
}

/////////////////////////////////////////////////////////////////
const InputData getInputData(const std::string t_string)
{
	InputData inputData;

	std::ifstream inputFile;

	// Read from file
	inputFile.open("data/" + t_string + ".txt");

	if (inputFile.is_open())
	{
		std::string line; // Holds one line of data

		// Get the first line
		if (std::getline(inputFile, line))
		{
			std::stringstream lineOne(line);
			std::string item;

			// Total books
			std::getline(lineOne, item, ' ');
			inputData.m_totalBooks = std::stoi(item);

			// Total Libraries
			std::getline(lineOne, item, ' ');
			inputData.m_numLibraries = std::stoi(item);

			// Total books
			std::getline(lineOne, item, ' ');
			inputData.m_numDays = std::stoi(item);

			// Get next line
			std::getline(inputFile, line);
			std::stringstream lineTwo(line);

			// Loop through all books
			while (std::getline(lineTwo, item, ' '))
			{
				inputData.m_bookScores.push_back(std::stoi(item));
			}

			// Loop through all libraries
			int index = 1; // Start from 1 because of use of %
			Library library;
			while (std::getline(inputFile, line))
			{
				std::stringstream lineStream(line);

				if (index % 2 == 1) // Even (Library information)
				{
					std::getline(lineStream, item, ' ');
					library.m_numBooks = std::stoi(item);

					std::getline(lineStream, item, ' ');
					library.m_daysToSignUp = std::stoi(item);

					std::getline(lineStream, item, ' ');
					library.m_booksPerDay = std::stoi(item);
				}
				else // Odd (Library book indices)
				{
					library.m_bookIDs.clear();

					// Loop book indices
					while (std::getline(lineStream, item, ' '))
					{
						library.m_bookIDs.push_back(std::stoi(item));
					}

					inputData.m_libraries.push_back(library);
				}

				index++;
			}
		}

		inputFile.close();
	}

	return inputData;
}

/////////////////////////////////////////////////////////////////
OutputData getSolutionData(const InputData t_inputData)
{
	OutputData outputData;

	// Find solution
	//for (int i = t_inputData.m_numPizzas - 1; i >= 0; i--)
	//{
	//	if (outputData.m_totalSlices + t_inputData.m_slicesPerPizza.at(i) > t_inputData.m_maximumSlices)
	//	{
	//		// step back
	//	}
	//	else
	//	{
	//		outputData.m_pizzaIndices.push(i);
	//		outputData.m_totalSlices += t_inputData.m_slicesPerPizza.at(i);
	//	}
	//}

	return outputData;
}

/////////////////////////////////////////////////////////////////
OutputData getSolutionData1(const InputData t_inputData)
{
	return OutputData();
}

/////////////////////////////////////////////////////////////////
void writeToFile(OutputData t_outputData, const std::string t_name)
{
	std::ofstream outputFile;

	outputFile.open("data/" + t_name + "_solution.txt");

	if (outputFile.is_open())
	{
		outputFile << t_outputData.m_numLibsSignedUp << "\n";

		int iteration = 0;
		for (OutputLibrary const& lib : t_outputData.m_libraries)
		{
			outputFile << lib.m_libIndex << " ";
			outputFile << lib.m_booksSent << "\n";

			for (int bookIndex = 0; bookIndex < lib.m_sentBookIndices.size(); bookIndex++)
			{
				outputFile << lib.m_sentBookIndices.at(bookIndex);

				// only add a space if another piece of data follows
				if (bookIndex != lib.m_sentBookIndices.size() - 1)
				{
					outputFile << " ";
				}
			}

			// only add a line break if another piece of data follows
			if (iteration != t_outputData.m_libraries.size() - 1)
			{
				outputFile << "\n";
			}

			iteration++;
		}

		outputFile.close();
	}
}

/////////////////////////////////////////////////////////////////

std::vector<int> getHighestFirst(Library& t_lib, std::vector<int>& t_bookScores)
{
	std::vector<std::pair<int, int>> values;

	for (int i : t_lib.m_bookIDs)
	{
		std::pair<int, int> p{ t_bookScores.at(i), i };
		values.push_back(p);
	}

	std::sort(values.begin(), values.end(), std::greater<>());

	std::vector<int> priority;

	for (std::pair<int,int> i : values)
	{
		priority.push_back(i.second);
	}

	return priority;
}

/////////////////////////////////////////////////////////////////

std::vector<int> getShortestSetup(std::vector<Library>& t_libraries)
{
	std::vector<std::pair<int, int>> times;

	for (int i = 0; i < t_libraries.size(); i++)
	{
		std::pair<int, int> p{ t_libraries.at(i).m_daysToSignUp, i };
	}

	std::sort(times.begin(), times.end());

	std::vector<int> priority;

	for (std::pair<int, int> i : times)
	{
		priority.push_back(i.second);
	}

	return priority;
}

/////////////////////////////////////////////////////////////////