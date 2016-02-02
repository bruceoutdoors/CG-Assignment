#ifndef TOWER_H
#define TOWER_H

#include "utilities/Lathe.hpp"
#include "utilities/Drawable.hpp"
#include "utilities/Transformable.hpp"

class Tower : public Drawable, public Transformable
{
    public:
        Tower();
        virtual ~Tower();

        void draw() override;
    protected:
    private:
        Lathe *bottomSec;
        Lathe *topSec;
};

#endif // TOWER_H
