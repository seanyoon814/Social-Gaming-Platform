#include "Config.h"
#include "Rules.h"
#include "PerPlayer.h"
#include "PerAudience.h"
#include "Constant.h"

class Game{
    public:
        Game(void) {};
        ~Game(void) {};

        void setConfig(Config::Config);
        void setRules(Rules::Rules);
        void setPerPlayer(PerPlayer::PerPlayer);
        void setPerAudience(PerAudience::PerAudience);
        void setConstant(Constant::Constant);
        
        Config::Config getConfig();
        Rules::Rules getRules();
        PerPlayer::PerPlayer getPerPlayer();
        PerAudience::PerAudience getPerAudience();
        Constant::Constant getConstant();

    protected:
        Config::Config config;
        Rules::Rules rules;
        PerPlayer::PerPlayer perPlayer;
        PerAudience::PerAudience perAudience;
        Constant::Constant constant;

}
