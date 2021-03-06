/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.
*/

#include "server/zone/objects/ship/ShipObject.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/packets/ship/ShipObjectMessage1.h"
#include "server/zone/packets/ship/ShipObjectMessage3.h"
#include "server/zone/packets/ship/ShipObjectMessage4.h"
#include "server/zone/packets/ship/ShipObjectMessage6.h"
#include "server/zone/packets/tangible/TangibleObjectMessage8.h"
#include "server/zone/packets/tangible/TangibleObjectMessage9.h"
#include "server/zone/Zone.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/planet/PlanetManager.h"


void ShipObjectImplementation::sendTo(SceneObject* player, bool doClose) {
	//info("testing");
	TangibleObjectImplementation::sendTo(player, doClose);
}

void ShipObjectImplementation::initializeTransientMembers() {
	TangibleObjectImplementation::initializeTransientMembers();
}

uint16 ShipObjectImplementation::getUniqueID() {
	uint32 hash = UnsignedLong::hashCode(getObjectID());
	uint16 id = (uint16) (hash ^ (hash >> 16));

	//info("uniqueId: 0x" + String::hexvalueOf(id), true);

	return id;
}

void ShipObjectImplementation::sendBaselinesTo(SceneObject* player) {
	//info("sending ship baselines", true);

	BaseMessage* ship3 = new ShipObjectMessage3(_this.getReferenceUnsafeStaticCast());
	player->sendMessage(ship3);


	//if (player->getParent().get() == _this.getReferenceUnsafeStaticCast() || getRootParent().get() == player) {
		BaseMessage* ship4 = new ShipObjectMessage4(_this.getReferenceUnsafeStaticCast());
		player->sendMessage(ship4);
	
		BaseMessage* ship1 = new ShipObjectMessage1(_this.getReferenceUnsafeStaticCast());
		player->sendMessage(ship1);
	//}

	BaseMessage* ship6 = new ShipObjectMessage6(_this.getReferenceUnsafeStaticCast());
	player->sendMessage(ship6);
/*
	BaseMessage* ship8 = new TangibleObjectMessage8(_this);
	player->sendMessage(ship8);

	BaseMessage* ship9 = new TangibleObjectMessage9(_this);
	player->sendMessage(ship9);*/
}
void ShipObjectImplementation::setParkedLocation(CityRegion* point) {
	parkedLocation = point;
}


void ShipObjectImplementation::notifyLoadFromDatabase() {
	TangibleObjectImplementation::notifyLoadFromDatabase();
	if (isInQuadTree())
		return;

	if (parkedLocation == NULL) {

		ZoneServer* zoneServer = getZoneServer();
		if (zoneServer == NULL) {
			return;
		}

		Zone* zone = zoneServer->getZone("corellia");
		if (zone == NULL) {
			return;
		}

		PlanetTravelPoint* point = zone->getPlanetManager()->getPlanetTravelPoint("Coronet Starport");

		if (point == NULL) {
			error("Coronet Starport not found.");
			return;
		}

		CityRegion* region = zone->getPlanetManager()->getRegionAt(point->getArrivalPositionX(), point->getArrivalPositionY());

		if (region == NULL) {
			error("Failed to get CityRegion object");
			return;
		}

		parkedLocation = region;

	}

}
