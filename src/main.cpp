#include <iostream>
#include <nats.h>

int main()
{
	std::cout << "NATS Client\n";
	natsConnection *nc;
	natsStatus status = natsConnection_ConnectTo(&nc, NATS_DEFAULT_URL);
	if (status != NATS_OK) {
		std::cerr << "Failed to connect: " << natsStatus_GetText(status) << '\n';
		return 1;
	}
	natsConnection_Destroy(nc);
	std::cout << "Shutting down...\n";
	return 0;
}