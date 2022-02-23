#include <iostream>
#include <stdio.h>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <SFML/Graphics.hpp>

using namespace::std;

int main(void){
    typedef boost::array<std::string, 3> array;
    array a;

    boost::asio::io_service io;
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
    cout << "Hello, world!" << endl;
    t.wait();
    a[0] = "mankind";
    sf::Window window(
        sf::VideoMode(640,480), "helo wolo");
    
    cout << "window is open : " << a[0] << endl;

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}