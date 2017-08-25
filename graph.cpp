#include "graph.hpp"
#include<stdlib>
#include<math>


mits::BitMapMatrix::BitMapMatrix(int nv){
     nvertex=nv;
     vbitmap=(char*)malloc((nvertex*nvertex)/8);
}

bool mits::BitMapMatrix::getBit(int i, int j){
        int bitpos=(i*nvertex)+j;
        int byteloc=(bitpos)/8;
        int bitoff=bitpos%8;
        int bitmask=pow(2,8-bitoff);
        if((this->vbitmap[byteloc]&=bitmask)!=1)
           return 0;
        else
           return 1;
}

void mits::BitMapMatrix::setBit(int i, int j){
        int bitpos=(i*nvertex)+j;
        int bytepos=(bitpos)/8;
        int bitoff=bitpos%8;
        int bitmask=pow(2,8-bitoff);
        this->vbitmap[bytepos]|=bitmask;
                    

}

void mits::BitMapMatrix::resetBit(int i, int j){
int bitpos=i*nvertex+j;
int byteloc=bitpos/8;
int bitoff=bitpos%8;
int bitmask=pow(2,8-bitoff);
vbitmap[byteloc]&=bitmask;

}


void mits::BitMapMatrix::deleteEntry(int v){


}




mits::Graph::Graph(const int nv, const int ne, std::vector<std::string> &vn, std::vector<std::string> &en, 
                   const int* adjcMat, RepType t){
   
    
   nvertex=nv;
   nedge=ne;
   vnames=vn;
   enames=en;
   repType=t;
        
  
    bmm=mits::BitMapMatrix(this->nvertex);
    
    for(int i=0;i<this->nvertex;i++){
        for(int j=0;j<this->nvertex;j++){
            if(*(adjcMat+i*this->nvertex+j) == 1)
                bmm.setBit(i,j);
            else 
                bmm.resetBit(i,j);
        }
    }
}
int mits::Graph::getVertexCount(){
    return this->nvertex;
}

int mits::Graph::getEdgeCount(){
    return this->nedge;
}

mits::RepType mits::Graph::getRepType(){
return this->repType;
}

