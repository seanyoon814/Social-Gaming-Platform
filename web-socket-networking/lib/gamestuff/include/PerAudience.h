#include <iostream>
#include <string>


class PerAudience {
    public:
     PerAudience(bool requireAudience, int gameID);

     ~PerAudience();

     void setAudienceSize(int size);

     int getAudienceSize();

     void setAudieceSide(std::string side);

     std::string getAudienceSide();

     private:
      bool requireAudience;

      std::string side;

      int size;

      int gameID;

};