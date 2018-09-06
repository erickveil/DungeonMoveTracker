#ifndef TABLEENTRYTEMPLATE_H
#define TABLEENTRYTEMPLATE_H

#include <QString>


template <class Thing>
class TableEntryTemplate
{
    Thing _result;
    int _weight;

public:
    TableEntryTemplate()
    {

    }

    TableEntryTemplate(Thing result, int weight)
    {
        _result = result;
        _weight = weight;
    }

    Thing result() const
    {
        return _result;
    }

    int weight() const
    {
        return _weight;
    }
};


#endif // TABLEENTRYTEMPLATE_H
