#include <iostream>
#include <fstream>
#include <string>
#include <cerrno>
#include <cstring>

bool openOutputFileStream(std::ofstream &ofs, const std::string &fileName)
{
    std::ifstream ifsFileAlreadyExist(fileName.c_str());

    //check if the output file alright exit
    if(ifsFileAlreadyExist.is_open())
    {
        std::cout << "Error: the file: " << fileName << " already exist" << std::endl;
        ifsFileAlreadyExist.close();
        return false;
    }

    //open the output file
    ofs.open(fileName.c_str(), std::ios_base::out);
    if (!ofs.is_open())
    {
        std::cout << "Error: opening file: " << fileName;
        std::cout << ": " << strerror(errno) << std::endl;
        return false;
    }
    return true;
}

bool openInputFileStream(std::ifstream &ifs, const std::string &fileName)
{
    ifs.open(fileName.c_str());
    if (!ifs.is_open())
    {
        std::cout << "Error: opening file: " << fileName;
        std::cout << ": " << strerror(errno) << std::endl;
        return false;
    }
    return true;
}

void replaceLine(std::string &line, const std::string &search, const std::string &replace)
{
    size_t pos;

    if (search.empty())
        return ;
    pos = 0;
    while (pos != std::string::npos)
    {
        pos = line.find(search, pos);
        if (pos == std::string::npos)
            break ;
        line.erase(pos, search.length());
        if (!replace.empty())
        {
            line.insert(pos, replace);
            pos+= replace.length();
        }
    }
}

bool replaceText(std::ifstream &ifs, std::ofstream &ofs, const std::string search, std::string replace)
{
	std::string	buffer;
	
	while ( std::getline(ifs, buffer ))
	{
		if (ifs.fail())
			return false;
		replaceLine(buffer, search, replace);
		ofs << buffer;
		if (!ifs.eof())
			ofs << std::endl;
	}
	return true;
}

int main(int argc, char **argv)
{
    std::ifstream ifstream;
    std::ofstream ofstream;
    std::string   strInputFileName, strSearch, strReplace, strOutputFileName; 
    int status = 0;

    if (argc != 4)
    {
        std::cout << "Usage: sed2: <filename> <search> <replace>" << std::endl;
        return 1;
    }

    //set the strs
    strInputFileName = argv[1];
    strSearch        = argv[2];
    strReplace       = argv[3];
    strOutputFileName = strInputFileName + ".replace";

    //trying open the files
    if (!openInputFileStream(ifstream, strInputFileName))
        return 1;
    if (!openOutputFileStream(ofstream, strOutputFileName))
    {
        ifstream.close();
        return 1;
    }

    //replace the text
    if(!replaceText(ifstream, ofstream, strSearch, strReplace))
        status = 1;

    //close the streams
    ifstream.close();
    ofstream.close();

    return status;
}
