#include <iostream>
#include <string>

#include "SimulationEngine.h"
#include "FileManager.h"
#include "GUI.h"

using namespace std;

int main(int argc, char* argv[])
{
    SimulationEngine simulation;
    FileManager fileManager;

    string inputFile;
    string outputFile = "output.txt";

    if (argc > 1)
    {
        inputFile = argv[1];
        if (argc > 2)
            outputFile = argv[2];
    }
    else
    {
        cout << "Enter input file name (e.g. sample1.txt): ";
        cin >> inputFile;
    }

    if (!fileManager.LoadInput(inputFile, &simulation))
    {
        cout << "Failed to load input file." << endl;
        return -1;
    }

    cout << "Input file loaded successfully." << endl;

    int choice;

    cout << endl;
    cout << "Select Run Mode:" << endl;
    cout << "1. Silent Mode" << endl;
    cout << "2. Interactive Mode" << endl;
    cout << "3. GUI Mode" << endl;
    cout << "Enter choice: ";

    cin >> choice;
    cin.ignore();

    if (choice == 1)
    {
        simulation.RunSilent();
    }
    else if (choice == 2)
    {
        simulation.RunInteractive();
    }
    else if (choice == 3)
    {
        GUI gui(&simulation);
        gui.Run();
    }
    else
    {
        cout << "Invalid choice." << endl;
        return -1;
    }

    fileManager.SaveOutput(outputFile, &simulation);

    cout << "Output file generated successfully." << endl;

    return 0;
}