/// <summary>
/// Google Hash Code Qualification
/// @Author Michael Rainsford Ryan & Ben Millar
/// @Date 20/02/2020
/// </summary>


#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

/////////////////////////////////////////////////////////////////
struct InputData
{
	
};


/////////////////////////////////////////////////////////////////
struct OutputData
{
	
};


/////////////////////////////////////////////////////////////////

const InputData getInputData(const std::string t_name);
OutputData getSolutionData(const InputData t_inputData);
void writeToFile(OutputData t_outputData, const std::string t_name);

int main()
{

}

/////////////////////////////////////////////////////////////////
const InputData getInputData(const std::string t_string)
{
	InputData inputData;

	std::ifstream inputFile;

	// Read from file
	inputFile.open("data/" + t_string + ".in");

	if (inputFile.is_open())
	{
		std::string line; // Holds one line of data

		// Get the first line
		if (std::getline(inputFile, line))
		{
			//std::stringstream lineOne(line);
			//std::string item;

			//// Maximum slices
			//std::getline(lineOne, item, ' ');
			//inputData.m_maximumSlices = std::stoi(item);

			//// Number of pizzas
			//std::getline(lineOne, item, ' ');
			//inputData.m_numPizzas = std::stoi(item);

			//// Loop through each piece of data
			//std::getline(inputFile, line);
			//std::stringstream lineTwo(line);

			//while (std::getline(lineTwo, item, ' '))
			//{
			//	inputData.m_slicesPerPizza.push_back(std::stoi(item));
			//}
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
void writeToFile(OutputData t_outputData, const std::string t_name)
{
	std::ofstream outputFile;

	outputFile.open("data/" + t_name + ".out");

	if (outputFile.is_open())
	{
		/*outputFile << t_outputData.m_pizzaIndices.size() << "\n";

		while (!t_outputData.m_pizzaIndices.empty())
		{
			outputFile << t_outputData.m_pizzaIndices.top();
			t_outputData.m_pizzaIndices.pop();

			if (!t_outputData.m_pizzaIndices.empty())
			{
				outputFile << " ";
			}
		}*/
	}
}

/////////////////////////////////////////////////////////////////