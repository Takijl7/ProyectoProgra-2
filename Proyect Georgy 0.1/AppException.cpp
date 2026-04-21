#include "AppException.h"
using namespace std;

AppException::AppException(const string& mensaje) : runtime_error(mensaje) {}