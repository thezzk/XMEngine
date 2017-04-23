//
//  BoundingBox.cpp
//  XMEngine
//
//  Created by thezzk on 17/4/22.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "BoundingBox.h"
#include "MathExtension.h"
namespace gEngine{
    
//Projection
    Projection::Projection(float min, float max)
    {
        this->min = min;
        this->max = max;
    }
    
    Projection::~Projection()
    {
    }
    
    bool Projection::overlap(Projection* proj)
    {
        if(min > proj->getMax()) return false ;
        if(max < proj->getMin()) return false ;
        
        return true ;
    }
    
    float Projection::getMax() const
    {
        return max;
    }
    
    float Projection::getMin() const
    {
        return min;
    }
//OBB
    OBB::OBB(std::vector<glm::vec2> v)
    {
        vertex = v;
    }
    
    OBB::~OBB()
    {
        
    }
    
    bool OBB::isCollidWithOBB(gEngine::OBB *obb)
    {
        std::vector<glm::vec2> axie1;
        std::vector<glm::vec2> axie2;
        
        axie1 = getAxies();
        axie2 = obb->getAxies();
        
        //Check for overlap for all of the axies
        for(int i = 0 ; i < 4 ; i ++)
        {
            Projection p1 = getProjection(axie1[i]);
            Projection p2 = obb->getProjection(axie1[i]);
            
            if(!p1.overlap(&p2))
                return false ;
        }
        
        for(int i = 0 ; i < 4 ; i ++)
        {
            Projection p1 = getProjection(axie2[i]);
            Projection p2 = obb->getProjection(axie2[i]);
            
            if(!p1.overlap(&p2))
                return false ;  
        }
        
        return true ;
    }
    
    std::vector<glm::vec2> OBB::getAxies()
    {
        std::vector<glm::vec2> retval;
        for(int i = 0 ; i < 4 ; i++)
        {
            glm::vec2 s;
            s = vertex[i] - vertex[(i+1)%4];
            s = glm::normalize(s);
            glm::vec2 r;
            r[0] = -s[1];
            r[1] = s[0];
            
            retval.push_back(r);
        }
        return retval;
    }
    
    Projection OBB::getProjection(glm::vec2 axie)
    {
        float min = 0;
        float max = 0;
        
        min = max = glm::dot(vertex[0], axie);
        for(int i = 1 ; i < 4 ; i ++)
        {
            float temp = 0 ;
            temp = glm::dot(vertex[i], axie);
            if(temp > max)
                max = temp ;
            else if(temp < min)
                min = temp ;
        }
        
        return Projection(min, max);  
    }
    
//BoundingBox
    BoundingBox::BoundingBox()
    {
        sizeScale = glm::vec2(1.0f, 1.0f);
        offset = glm::vec2(0.0f, 0.0f);
    }
    
    BoundingBox::BoundingBox(glm::vec2 sizeScale, glm::vec2 offset)
    {
        this->sizeScale = sizeScale;
        this->offset = offset;
    }
    
    glm::vec2 BoundingBox::getSizeScale() const
    {
        return sizeScale;
    }
    
    void BoundingBox::setSizeScale(glm::vec2 sizeSca)
    {
        sizeScale =sizeSca;
    }
    
    glm::vec2 BoundingBox::getOffset() const
    {
        return offset;
    }
    
    void BoundingBox::setOffset(glm::vec2 off)
    {
        offset = off;
    }
    
    std::vector<glm::vec2> BoundingBox::getBoxVertex(Transform transform)
    {
        GLfloat hHeight = sizeScale[1] * transform.getHeight() / 2;
        GLfloat hWidth = sizeScale[0] * transform.getWidth() / 2;
        GLfloat thetaRad = transform.getRotationInRad();
        glm::vec2 leftTopV = glm::rotate_2d(glm::vec2(-hWidth, hHeight), thetaRad);
        glm::vec2 rightTopV = glm::rotate_2d(glm::vec2(hWidth, hHeight), thetaRad);
        glm::vec2 rightBottomV = glm::rotate_2d(glm::vec2(hWidth, -hHeight), thetaRad);
        glm::vec2 leftBottomV = glm::rotate_2d(glm::vec2(-hWidth, -hHeight), thetaRad);
        glm::vec2 frontDir = glm::vec2(cosf(thetaRad), sinf(thetaRad));
        GLfloat worldXOffset = frontDir[0] * offset[1] + frontDir[1] * offset[0];
        GLfloat worldYOffset = frontDir[1] * offset[1] - frontDir[0] * offset[0];
        glm::vec2 worldOffset = glm::vec2(worldXOffset, worldYOffset);
        leftTopV = leftTopV + worldOffset + transform.getPosition();
        rightTopV = rightTopV + worldOffset + transform.getPosition();
        rightBottomV = rightBottomV + worldOffset + transform.getPosition();
        leftBottomV = leftBottomV + worldOffset + transform.getPosition();
        std::vector<glm::vec2> retval;
        retval.push_back(leftTopV);
        retval.push_back(rightTopV);
        retval.push_back(rightBottomV);
        retval.push_back(leftBottomV);
        return retval;
        
    }
}// namespace gEngine
