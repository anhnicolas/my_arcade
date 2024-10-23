/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** dlManipulation
*/

#include "../../include/Core/CoreModule.hpp"
#include "../../include/Core/ICoreModule.hpp"
#include "../../include/Core/LdlWrapper.hpp"
#include "../../include/Libs.hpp"
#include "../../include/GlobalClasses/Errors.hpp"

LdlWrapper::LdlWrapper(const std::string &path)
{
    openLib(path);
}

void LdlWrapper::openLib(const std::string &path)
{
    std::cout << "Loading library : " << path << std::endl;
    _handle = dlopen(path.c_str(), RTLD_LAZY);
    if (!_handle)
        throw Error(dlerror());
}

void LdlWrapper::closeLib()
{
    if (_handle)
        dlclose(_handle);
}

void *LdlWrapper::getHandle() const
{
    return _handle;
}

template<typename T>
T LdlWrapper::createLib(const std::string& path)
{
    typedef T (*func_t)();
    auto func = reinterpret_cast<func_t>(dlsym(_handle, path.c_str()));

    if (!func)
        throw Error(dlerror());
    return func();
}

template std::shared_ptr<AGraphicalModule> LdlWrapper::createLib<std::shared_ptr<AGraphicalModule> >(const std::string& path);
template std::shared_ptr<AGameModule> LdlWrapper::createLib<std::shared_ptr<AGameModule> >(const std::string& path);
