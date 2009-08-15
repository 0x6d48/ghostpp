/*

   Copyright [2008] [Trevor Hogan]

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

   CODE PORTED FROM THE ORIGINAL GHOST PROJECT: http://ghost.pwner.org/

*/

#ifndef GAME_ADMIN_H
#define GAME_ADMIN_H

//
// CAdminGame
//

class CCallableBanCheck;
class CCallableBanAdd;
class CCallableGameAdd;
class CCallableGamePlayerSummaryCheck;
class CCallableDotAPlayerSummaryCheck;

typedef pair<string,CCallableBanCheck *> PairedBanCheck;
typedef pair<string,CCallableBanAdd *> PairedBanAdd;
typedef pair<string,CCallableGamePlayerSummaryCheck *> PairedGPSCheck;
typedef pair<string,CCallableDotAPlayerSummaryCheck *> PairedDPSCheck;

typedef pair<string,uint32_t> TempBan;

class CAdminGame : public CBaseGame
{
protected:
	string m_Password;
	vector<TempBan> m_TempBans;

public:
	CAdminGame( CGHost *nGHost, CMap *nMap, CSaveGame *nSaveGame, uint16_t nHostPort, unsigned char nGameState, string nGameName, string nPassword );
	virtual ~CAdminGame( );

	virtual bool Update( void *fd, void *send_fd );
	virtual void SendWelcomeMessage( CGamePlayer *player );
	virtual void EventPlayerJoined( CPotentialPlayer *potential, CIncomingJoinPlayer *joinPlayer );
	virtual void EventPlayerBotCommand( CGamePlayer *player, string command, string payload );
};

#endif
