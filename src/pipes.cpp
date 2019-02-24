

#include <cassert>
#include "pipes.h"


#define DEBUG 

bool Point::IsValid() {
  return x >= 0 && y >= 0 && x < PipePuzzle::length && y < PipePuzzle::length;
}

bool Point::operator==(Point& other) {
  return x == other.x && y == other.y;
}
Point::Point() {
  x = -1;
  y = -1;
}
Point::Point(int x, int y) {
  this->x = x;
  this->y= y;
}

NeighborList::NeighborList(void) : p1(-1, -1), p2(-1, -1) {
  
}

NeighborList Cell::GetNeighbors() {
  NeighborList ret;
  switch (cellType) {
  case NorthEast:
    ret.p1 = Point(pos.x + 1, pos.y);
    ret.p2 = Point(pos.x, pos.y + 1);
    break;
  case NorthWest:
    ret.p1 = Point(pos.x, pos.y + 1);
    ret.p2 = Point(pos.x - 1, pos.y);
    break;
  case SouthWest:
    ret.p1 = Point(pos.x, pos.y - 1);
    ret.p2 = Point(pos.x - 1, pos.y);
    break;
  case SouthEast:
    ret.p1 = Point(pos.x, pos.y - 1);
    ret.p2 = Point(pos.x + 1, pos.y);
    break;
  case NorthSouth:
    ret.p1 = Point(pos.x, pos.y + 1);
    ret.p2 = Point(pos.x, pos.y - 1);
    break;
  case EastWest:
    ret.p1 = Point(pos.x + 1, pos.y);
    ret.p2 = Point(pos.x - 1, pos.y);
    break;
  }
  return ret;
}

void Cell::Rotate() {

  switch (cellType) {
  case NorthEast:
    cellType = SouthEast;
    break;
  case NorthWest:
    cellType = NorthEast;
    break;
  case SouthWest:
    cellType = NorthWest;
    break;
  case SouthEast:
    cellType = SouthWest;
    break;
  case NorthSouth:
    cellType = EastWest;
    break;
  case EastWest:
    cellType = NorthSouth;
    break;
  }
}

bool Cell::IsDirectlyConnected(Cell other) {
  NeighborList list1 = GetNeighbors(); 
  NeighborList list2 = other.GetNeighbors();

  bool thisTouchOther = this->pos == list2.p1 || this->pos == list2.p2;
  bool otherTouchThis = other.pos == list1.p1 || other.pos == list1.p1;

  return thisTouchOther && otherTouchThis;
}

Cell& Cell::operator=(Cell& other) {
  this->pos.x = other.pos.x;
  this->pos.y = other.pos.y;

  return *this;
}
PipePuzzle::PipePuzzle() {
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      board[i][j].pos.x = i;
      board[i][j].pos.y = j;
      board[i][j].cellType = NorthSouth;
    }
  }
}
bool PipePuzzle::CanReach(Point a, Point b) {
  //
  if (a == b) {
    return true;
  }
  if (!a.IsValid() || !b.IsValid()) {
    return false;
  }

  if (GetPos(a).IsDirectlyConnected(GetPos(b))) {
    return true;
  }

  if (GetPos(a).flag) {
    return false;
  }
  GetPos(a).flag = 1;
  NeighborList list = GetPos(a).GetNeighbors();
  bool ret1 = CanReach(list.p1,b);
  bool ret2 = CanReach(list.p2,b);



  
  return ret1 || ret2;
}
void PipePuzzle::SetType(Point a, CellType t) {

  GetPos(a).cellType = t;
  //do stuff
}

void PipePuzzle::ClearFlags() {
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      board[i][j].flag = 0;
    }
  }
}

Cell& PipePuzzle::GetPos(int x, int y) {
  return board[x][y];
}
Cell& PipePuzzle::GetPos(Point p) {
  assert(p.IsValid());
  int x = p.x;
  int y = p.y;

  return board[x][y];
}


bool PipePuzzle::IsSolved() {
  ClearFlags();

  Cell begin = GetPos(0, length / 2 );
  Cell end = GetPos(length - 1, length / 2 );

  bool connectedToBegin = begin.cellType == NorthWest || begin.cellType == SouthWest || begin.cellType == EastWest;
  bool connectedToEnd = begin.cellType == NorthEast || begin.cellType == SouthEast || begin.cellType == EastWest;

  return connectedToBegin && connectedToEnd && CanReach(begin.pos, end.pos);
}



#ifdef DEBUG
#include <iostream>

void printPuz(PipePuzzle& pp) {
  std::cout << "====BOARD START=====" << std::endl;
  for (int y = PipePuzzle::length - 1; y >= 0; y--) {
    for (int x = 0; x < PipePuzzle::length; x++) {
      std::cout << pp.GetPos(x, y).cellType;
    }
    std::cout << std::endl;
  }
  std::cout << "====BOARD END=====" << std::endl;
}
void test1() {
  
  PipePuzzle pp;

  Point a(0, 0);
  Point b(0, 1);
  Point c(0, 2);
  Point d(1, 1); 
  pp.SetType(a, NorthSouth);
  pp.SetType(b, NorthSouth);
  pp.SetType(c, EastWest);
  pp.SetType(d, EastWest);


  assert(pp.GetPos(a).IsDirectlyConnected(pp.GetPos(b)));
  assert(!pp.GetPos(b).IsDirectlyConnected(pp.GetPos(c)));
  assert(!pp.GetPos(a).IsDirectlyConnected(pp.GetPos(d)));
  printPuz(pp);
}




void test2() {
  PipePuzzle pp; 

  for (int i = 0; i < PipePuzzle::length; i++) {
    pp.SetType(Point(i, PipePuzzle::length / 2), EastWest);
  }


  printPuz(pp);
  assert(pp.IsSolved());

  
}
int main() {
  test1();
  test2();
}
#endif

