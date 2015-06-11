/*
 * \file IPBan.h
 *
 *  Created on: \date 30 mai 2015
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_IP_IPBAN_H_
#define SRC_SERVER_SHARED_IP_IPBAN_H_

#include <Databases/CRUD.h>

enum IPBanDatabaseStatements {
	REALMS_SEL_IPBANNED_INFOSSURIPBANNIES,
	REALMS_INS_IPBANNED_BANIP,
	REALMS_DEL_IPBANNED_DEBANIP,
	REALMS_UPD_IPBANNED_DEBANIP
};


/*
 *
 *
 *
 */
class IPBan : public CRUD {
public:
	IPBan(std::string hostip);
	virtual ~IPBan();

	bool create(int idTransaction = 0);
	bool read(int idTransaction = 0);
	bool update(int idTransaction = 0);
	bool suppr(int idTransaction = 0);

	time_t getBandate() const;
	void setBandate(time_t bandate);
	int getBannedby() const;
	void setBannedby(int bannedby);
	int getIdIpBanned() const;
	void setIdIpBanned(int idIpBanned);
	const std::string& getIp() const;
	void setIp(const std::string& ip);
	const std::string& getRaison() const;
	void setRaison(const std::string& raison);
	time_t getUnbandate() const;
	void setUnbandate(time_t unbandate);

private:
	int id_ip_banned;
	std::string ip;
	time_t bandate;
	time_t unbandate;
	std::string raison;
	int bannedby;
};

#endif /* SRC_SERVER_SHARED_IP_IPBAN_H_ */
