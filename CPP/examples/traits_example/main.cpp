#include <iostream>
using namespace std;

template<typename T>
struct impl_traits {
    static const bool value = false;
};

template<typename T>
void do_something() {
    if (impl_traits<T>::value) {
        T::new_impl();
        } else {
        T::old_impl();
        }
};

class foo {
public:
    static void old_impl() {
        cout << "[foo] Old implementation" << endl;
        }

    static void new_impl() {
        cout << "[foo] New implementation" << endl;
        }
};

class bar {
public:
    static void old_impl() {
        cout << "[bar] Old implementation" << endl;
        }

    static void new_impl() {
        cout << "[bar] New implementation" << endl;
        }
};

template<>
struct impl_traits<foo> {
    static const bool value = true;
};


int main() {
    do_something<foo>();
    do_something<bar>();

    return 0;
}
