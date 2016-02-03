#pragma once

#include "utilities/Lathe.hpp"
#include "utilities/Drawable.hpp"
#include "utilities/Transformable.hpp"

class CurveTower : public Drawable, public Transformable
{
    public:
        CurveTower();
        virtual ~CurveTower();

        void draw() override;
    protected:
    private:
        Lathe *bottomSec;
        Lathe *topSec;
};


