#include "scene.h"

Scene::Scene() {}

Stack &Scene::get_s4()
{
    return this->s4;
}
Stack &Scene::get_s3()
{
    return this->s3;
}

Stack &Scene::get_s2()
{
    return this->s2;
}

Stack &Scene::get_s1()
{
    return this->s1;
}

Bookcase &Scene::get_bc()
{
    return this->bc;
}

QVector<Book>& Scene::get_all_books()
{
    return this->all_books;
}
