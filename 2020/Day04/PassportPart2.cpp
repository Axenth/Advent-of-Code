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
            if (byr.empty() == false)
                byr = byr.substr(4, byr.find(" ") - 4);
            if (iyr.empty() == false)
                iyr = iyr.substr(4, iyr.find(" ") - 4);
            if (eyr.empty() == false)
                eyr = eyr.substr(4, eyr.find(" ") - 4);
            if (hgt.empty() == false)
                hgt = hgt.substr(4, hgt.find(" ") - 4);
            if (hcl.empty() == false)
                hcl = hcl.substr(4, hcl.find(" ") - 4);
            if (ecl.empty() == false)
                ecl = ecl.substr(4, ecl.find(" ") - 4);
            if (pid.empty() == false)
                pid = pid.substr(4, pid.find(" ") - 4);
            if (cid.empty() == false)
                cid = cid.substr(4, cid.find(" ") - 4);
        }

        static bool isValidChar(char c)
        {
            if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f'))
                return (true);
            return (false);
        }

        static bool isValidNumber(char c)
        {
            if (c >= '0' && c <= '9')
                return (true);
            return (false);
        }

        bool isValid()
        {
            int tempbyr = 0;
            int tempiyr = 0;
            int tempeyr = 0;
            int temphgt = 0;
            int hgttype = 0;
            try
            {
                tempbyr = std::stoi(byr, nullptr, 0);
                tempiyr = std::stoi(iyr, nullptr, 0);
                tempeyr = std::stoi(eyr, nullptr, 0);
                temphgt = std::stoi(hgt, nullptr, 0);
            } catch(...)
            {
                return false;
            }
            if (tempbyr < 1920 || tempbyr > 2002 || byr.length() > 4 || byr.length() < 4)
                return false;
            if (tempiyr < 2010 || tempiyr > 2020 || iyr.length() > 4 || iyr.length() < 4)
                return (false);
            if (tempeyr < 2020 || tempeyr > 2030 || eyr.length() > 4 || eyr.length() < 4)
                return (false);

            if (hgt.c_str()[hgt.length() - 1] == 'm' && hgt.c_str()[hgt.length() - 2] == 'c')
                hgttype = 1;
            else if (hgt.c_str()[hgt.length() - 1] == 'n' && hgt.c_str()[hgt.length() - 2] == 'i')
                hgttype = 2;
            if ((hgttype == 1 && (temphgt < 150 || temphgt > 193)) || (hgttype == 2 && (temphgt < 59 || temphgt > 76)) || hgttype == 0)
                return (false);

            if (hcl.length() > 7 || hcl.length() < 7)
                return (false);
            
            const char *temp = hcl.c_str();
            if (temp[0] != '#')
                return (false);
            for (int i = 1; i < 7; i++)
                if (isValidChar(temp[i]) == false)
                   return (false);

            if (ecl.compare(0, ecl.size(), "amb") == 0 ||
                ecl.compare(0, ecl.size(), "blu") == 0 ||
                ecl.compare(0, ecl.size(), "brn") == 0 ||
                ecl.compare(0, ecl.size(), "gry") == 0 ||
                ecl.compare(0, ecl.size(), "grn") == 0 ||
                ecl.compare(0, ecl.size(), "hzl") == 0 ||
                ecl.compare(0, ecl.size(), "oth") == 0)
                ;
            else
                return (false);

            if (pid.length() < 9 || pid.length() > 9)
                return (false);

            const char *temp2 = pid.c_str();
            for (int i = 0; i < 9; i++)
                if (isValidNumber(temp2[i]) == false)
                    return (false);
            return (true);
        }
};

int main(void)
{
    int size = 2000;
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
            temp->pid.empty() != true && temp->isValid() == true)
            valid_list.push_back(temp);
        else
            invalid_list.push_back(temp);
        
    }
    
 
    /* *PRINT INVALID ONES (DEBUG)*/ 
    /*for(auto it = valid_list.begin(); it != valid_list.end(); it++)
    {
        passport *temp = *it;
        std::cout << "byr:" << temp->byr << std::endl;
        std::cout << "iyr:" << temp->iyr << std::endl;
        std::cout << "eyr:" << temp->eyr << std::endl;
        std::cout << "hgt:" << temp->hgt << std::endl;
        std::cout << "hcl:" << temp->hcl << std::endl;
        std::cout << "ecl:" << temp->ecl << std::endl;
        std::cout << "pid:" << temp->pid << std::endl;
        std::cout << "cid:" << temp->cid << std::endl;
        std::cout << std::endl;
        
    } */

    file.close();
    std::cout << "Found " << valid_list.size() << " Valid Passports!" << std::endl;
}