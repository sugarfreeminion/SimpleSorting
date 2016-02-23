#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

void StringToDouble(string val, double& dVal);

int main(int argc, char* argv[])
{
    ifstream inputFile(argv[1]);
    string line;

    if(inputFile.is_open())
    {
        cout.precision(3);

        while(getline(inputFile,line))
        {
            vector<double> elements;

            //cout << line << endl;
            
            stringstream lineStream(line);
            string temp;

            while(getline(lineStream,temp,' '))
            {
                double dVal;

                StringToDouble(temp, dVal);

                elements.push_back(dVal);
            }

            sort(elements.begin(),elements.end());

            for(vector<double>::const_iterator it=elements.begin();
                it!=elements.end();
                ++it)
            {
                if(it != elements.end()-1)
                {
                    cout << fixed << *it << " ";
                }
                else
                {
                    cout << fixed << *it << endl;
                }
            }
        }
        
        inputFile.close();
    }

    return 0;
}

void StringToDouble(string val, double& dVal)
{
    stringstream valStream(val);

    valStream >> dVal;

}
