#include "SimpleMelody.h"

SimpleMelody::SimpleMelody()
{
    _head = nullptr;
    _cursor = nullptr;
}

SimpleMelody::~SimpleMelody()
{
    Node *next = _head;

    while (next)
    { // iterate over all elements
        Node *deleteMe = next;
        next = next->next; // save pointer to the next element
        delete deleteMe;   // delete the current entry
    }
}

void SimpleMelody::addMelody(Melody *melody)
{
    Node *n = new Node();
    n->melody = melody;
    n->next = nullptr;
    if (_head == nullptr)
    {
        _head = n;
        _cursor = n;
    }
    else
    {
        Node *_cur = _head;
        while (_cur->next != nullptr)
        {
            _cur = _cur->next;
        }
        _cur->next = n;
        _cur = nullptr;
    }
    n = nullptr;
}
bool SimpleMelody::hasNext()
{
    return (_cursor != nullptr && _cursor->melody->hasNext());
}
void SimpleMelody::restart()
{
    Node *n = _head;
    while (n != nullptr)
    {
        n->melody->restart();
        n = n->next;
    }
    _cursor = _head;
    n = nullptr;
}
Note *SimpleMelody::next()
{

    Note *n = _cursor->melody->next();
    if (!_cursor->melody->hasNext())
    {
        _cursor = _cursor->next;
    }
    return n;
}