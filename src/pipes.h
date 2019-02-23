

enum CellType {
               NorthEast, //North east means north direction and east direction, not actually north esat
               NorthWest,
               SouthWest,
               SouthEast,
               NorthSouth,
               EastWest
};
struct Point {
  int x;
  int y;
  bool IsValid();
  Point(int x, int y);
  Point();
  bool operator==(Point& other);
};

struct NeighborList {
  Point p1;
  Point p2;
  NeighborList(void);
};
class Cell {

 public:
  bool flag;
  
  Point pos;
  Cell& operator=(Cell& other);
  CellType cellType;
  
  NeighborList GetNeighbors();


  // checks if this and other are connected to each other
  bool IsDirectlyConnected(Cell other);
  void Rotate();
  

};

class PipePuzzle {

  
  

 public:
  static const int length = 10;
  PipePuzzle (); 
  bool CanReach(Point a, Point b);

  
  void SetType(Point a, CellType t);
  void Regenerate(); //actually changes the pipes
  void Scramble(); //just rotates the pipes
  void ClearFlags();
  Cell& GetPos(Point a);
  Cell& GetPos(int x, int y);
  
 private:
  Cell board[length][length];
};
