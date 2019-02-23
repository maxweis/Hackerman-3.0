

#include <cassert>
#include "pipes.h"


#define DEBUG 

bool Point::IsValid() {
  return x > 0 && y > 0 && x < PipePuzzle::length && y < PipePuzzle::length;
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

PipePuzzle::PipePuzzle() {
  
}
bool PipePuzzle::CanReach(Point a, Point b) {
  
  return true;
}
PipePuzzle::
void PipePuzzle::SetType(Point a, CellType t) {

  //do stuff
}


Cell& PipePuzzle::GetPos(Point p) {
  assert(p.IsValid());
  int x = p.x;
  int y = p.y;

  return board[x][y];
}

#ifdef DEBUG
int main() {
  PipePuzzle pp;

  Point a(0, 0);
  Point b(0, 1);
  pp.SetType(a, NorthSouth);
  pp.SetType(b, NorthSouth);

  assert(pp.CanReach(a, b));
}
#endif

