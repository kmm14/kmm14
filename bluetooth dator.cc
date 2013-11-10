#include <string>
#include <boost/asio.hpp>
using namespace::boost::asio;

serial_port_base::baud_rate BAUD(9600);
serial_port_base::parity PARITY(serial_port_base::parity::none);
serial_port_base::stop_bits STOP(serial_port_base::stop_bits::one);

void SendDataViaSerialPort(const std::string& to_write)
{
        io_service io;
        serial_port port(io, "COM4");
        port.set_option(BAUD);
        port.set_option(PARITY);
        port.set_option(STOP);

        write(port, buffer(to_write,1));
}


int main()
{
	for(;;)
SendDataViaSerialPort("0");

}