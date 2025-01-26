/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:58:48 by hehuang           #+#    #+#             */
/*   Updated: 2025/01/20 18:32:31 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

std::string	find_and_replace(std::string	line, std::string s1, std::string s2)
{
	std::string res;
	int	pos = line.find(s1, 0);
	for (int i = 0; i < line.size(); i++)
	{
		if (i == pos)
		{
			if (s1.size() > s2.size())
				i += s1.size();
			else
				i += s2.size();
			res += s2;
			pos = line.find(s1, i);
			i--;
		}
		else 
			res.push_back(line[i]);
	}
	return (res);
}

int main(int argc, char **argv) {
	
	
	if (argc == 4)
	{
		std::string replacefile = argv[1];
		std::string line;
		replacefile += ".replace";
		std::ifstream inFile(argv[1]);
		if (!inFile)
		{
			std::cerr << "Error while opening " << argv[1] << std::endl;
			return (1);
		}
		std::ofstream outFile(replacefile);
		if (outFile.is_open())
		{
			while (std::getline(inFile, line))
			{
				line = find_and_replace(line, argv[2], argv[3]);
				outFile << line << std::endl;
			}
			outFile.close();
			inFile.close();
		}
		else
		{
			std::cerr << "Error while opening/creating " << replacefile << std::endl;
			inFile.close();
			return (1);
		}
	}
    return 0;
}
