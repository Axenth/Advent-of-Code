#include <iostream>
#include <fstream>
#include <vector>

class passport{
    public:
        std::string byr, iyr, eyr, hgt, hcl , ecl , pid, cid;
        passport(){
            byr = "";
            iyr = "";
            eyr = "";
            hgt = "";
            hcl = "";
            ecl = "";
            pid = "";
            cid = "";
        }

        void update()
        {
            byr = byr.substr(0, byr.find(" "));
            iyr = iyr.substr(0, iyr.find(" "));
            eyr = eyr.substr(0, eyr.find(" "));
            hgt = hgt.substr(0, hgt.find(" "));
            hcl = hcl.substr(0, hcl.find(" "));
            ecl = ecl.substr(0, ecl.find(" "));
            pid = pid.substr(0, pid.find(" "));
            cid = cid.substr(0, cid.find(" "));
        }
};

int main(void)
{
    int size = 1070;
    std::vector<passport*> pass_list;
    std::vector<passport*> valid_list;
    std::vector<passport*> invalid_list;
    passport *temp_pass = new passport();
    

    std::ifstream file("input");
    if (file.is_open())
    {
        std::string line;
        for(int i = 0 ; i < size; i++)
        {
            std::getline(file, line);
            if (line.empty() == true)
            {
                pass_list.push_back(temp_pass);
                temp_pass = new passport();
            }
            if(line.find("byr:") != std::string::npos)
                temp_pass->byr = line.substr(line.find("byr:"), line.length());
            if(line.find("iyr:") != std::string::npos)
                temp_pass->iyr = line.substr(line.find("iyr:"), line.length());
            if(line.find("eyr:") != std::string::npos)
                temp_pass->eyr = line.substr(line.find("eyr:"), line.length());
            if(line.find("hgt:") != std::string::npos)
                temp_pass->hgt = line.substr(line.find("hgt:"), line.length());
            if(line.find("hcl:") != std::string::npos)
                temp_pass->hcl = line.substr(line.find("hcl:"), line.length());
            if(line.find("ecl:") != std::string::npos)
                temp_pass->ecl = line.substr(line.find("ecl:"), line.length());
            if(line.find("pid:") != std::string::npos)
                temp_pass->pid = line.substr(line.find("pid:"), line.length());
            if(line.find("cid:") != std::string::npos)
                temp_pass->cid = line.substr(line.find("cid:"), line.length());      
        }
    }
    for(auto it = pass_list.begin(); it != pass_list.end(); it++)
    {
        passport *temp = *it;
        temp->update();
        if (temp->byr.empty() != true && temp->iyr.empty() != true && temp->eyr.empty() != true &&
            temp->hgt.empty() != true && temp->hcl.empty() != true && temp->ecl.empty() != true &&
            temp->pid.empty() != true)
            valid_list.push_back(temp);
        else
            invalid_list.push_back(temp);
        
    }
 
    /* *PRINT INVALID ONES (DEBUG)*
    for(auto it = valid_list.begin(); it != valid_list.end(); it++)
    {
        passport *temp = *it;
        std::cout << temp->byr << std::endl;
        std::cout << temp->iyr << std::endl;
        std::cout << temp->eyr << std::endl;
        std::cout << temp->hgt << std::endl;
        std::cout << temp->hcl << std::endl;
        std::cout << temp->ecl << std::endl;
        std::cout << temp->pid << std::endl;
        std::cout << temp->cid << std::endl;
        std::cout << std::endl;
        
    } */

    file.close();
    std::cout << "Found " << valid_list.size() << " Valid Passports!" << std::endl;
}