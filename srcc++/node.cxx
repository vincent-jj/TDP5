#include "node.hxx"
#define __MAX_DEPTH__ 10000

using namespace std;

node::node(){
    this->hasChild = false;
    this->depth = 0;
    this->completed = false;
}

node::node(int depths) : depth(depths){
    this->hasChild = false;
    this->completed = false;
}

void node::makeChild(){
    int i;
    vector<particle*> quadtree1, quadtree2, quadtree3, quadtree4;
    
    for(i = 0; i < this->Particles.size(); ++i){
        if(this->Particles[i]->pos.x < ((this->pos.x)+(this->widthSize/2.))){
            if(Particles[i]->pos.y < (this->pos.y + (this->widthSize/2.)))
                quadtree1.push_back(Particles[i]);
            else
                quadtree3.push_back(Particles[i]);
        }
        else{
            if(Particles[i]->pos.y < (this->pos.y + (this->heightSize /2.)))
                quadtree2.push_back(Particles[i]);
            else
                quadtree4.push_back(Particles[i]);
        }
    }

    node *q1 = new node(this->depth+1);
    node *q2 = new node(this->depth+1);
    node *q3 = new node(this->depth+1);
    node *q4 = new node(this->depth+1); 
    
    q1->setParameters(quadtree1, this->widthSize/2., this->heightSize/2., this->pos.x, this->pos.y);
    q2->setParameters(quadtree2, this->widthSize/2., this->heightSize/2., this->pos.x, this->pos.y);
    q3->setParameters(quadtree3, this->widthSize/2., this->heightSize/2., this->pos.x, this->pos.y);
    q4->setParameters(quadtree4, this->widthSize/2., this->heightSize/2., this->pos.x, this->pos.y);     
    this->Child.push_back(q1);
    this->Child.push_back(q2);
    this->Child.push_back(q3);
    this->Child.push_back(q4);
    
    this->hasChild = true;

    return;
}

void node::setParameters(vector<particle*>particles, float particlesWidth, float particlesHeight, float pos_x = 0., float pos_y = 0.){
    int i;
    this->widthSize = particlesWidth;
    this->heightSize = particlesHeight;
    this->Particles = particles;
    pos.x = pos_x;
    pos.y = pos_y;

    float weigh = 0.;
    coords BCenter; BCenter.x = 0.; BCenter.y = 0.;

    for(i = 0; i < particles.size(); ++i){
        weigh += particles[i]->wei;
        BCenter.x += particles[i]->pos.x;
        BCenter.y += particles[i]->pos.y;
    }
    
    unsigned size = particles.size();
    this->barycenter.x = BCenter.x / (float)size;
    this->barycenter.y = BCenter.y / (float)size;

    if(Particles.size() > 1 && this->depth < __MAX_DEPTH__)
        this->makeChild();
    return;
}

void node::reset(){
    this->Particles.clear();
    unsigned i;
    for(i = 0; i<this->Child.size(); ++i)
        this->Child[i]->reset();
    for(i = 0; i<this->Child.size(); ++i)
        delete Child[i];
    this->Child.clear();
    this->hasChild = false;
    this->completed = false;
    return;
}

node::~node(){}
