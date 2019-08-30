#include<iostream>
#include<iomanip>
#include<string>
#include "TaskTree.h"
using namespace std;

void setupTree(Tree);

void calcCompletion (TreeItr);

void determineCritical(TreeItr);

void postorderPrint(TreeItr);

int cTime;

int main()
{
Tree theJobs;
TreeItr Top;
Top = theJobs.TreeRoot();
setupTree(theJobs);
calcCompletion(Top);
cout << "PROJECT SCHEDULE" << endl;
cout<<endl;
postorderPrint(Top);
cout<<endl;
cout<< "Total Time For Project: "<<cTime<<" weeks"<<endl;
}

void setupTree(Tree theJobs)
{
  TreeItr current, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;

  Task tmp;

  current = theJobs.TreeRoot();
  tmp.element = "Install Product";
  tmp.duration = 4;
  tmp.critical = 1;
  current.changeInfo(tmp);

  a = theJobs.createChild(current);
  tmp.element = "Test Main";
  tmp.duration = 4;
  tmp.critical = 0;
  a.changeInfo(tmp);

  b = theJobs.createChild(current);
  tmp.element = "Get CEO Report";
  tmp.duration = 1;
  tmp.critical = 0;
  b.changeInfo(tmp);

  c = theJobs.createChild(current);
  tmp.element = "Set Up Platform";
  tmp.duration = 1;
  tmp.critical = 0;
  c.changeInfo(tmp);

  d = theJobs.createChild(current);
  tmp.element = "Test User Interface";
  tmp.duration = 4;
  tmp.critical = 1;
  d.changeInfo(tmp);

  e = theJobs.createChild(current);
  tmp.element = "Install Sort";
  tmp.duration = 1;
  tmp.critical = 1;
  e.changeInfo(tmp);

  f = theJobs.createChild(current);
  tmp.element = "Install Lib";
  tmp.duration = 1;
  tmp.critical = 1;
  f.changeInfo(tmp);

  g = theJobs.createChild(current);
  tmp.element = "Write Main";
  tmp.duration = 3;
  tmp.critical = 1;
  g.changeInfo(tmp);

  h = theJobs.createChild(current);
  tmp.element = "Get CIO input";
  tmp.duration = 1;
  tmp.critical = 0;
  h.changeInfo(tmp);

  i = theJobs.createChild(current);
  tmp.element = "Order Platform";
  tmp.duration = 2;
  tmp.critical = 0;
  i.changeInfo(tmp);

  j = theJobs.createChild(current);
  tmp.element = "Write I/O";
  tmp.duration = 3;
  tmp.critical = 1;
  j.changeInfo(tmp);

  k = theJobs.createChild(current);
  tmp.element = "Design Engine";
  tmp.duration = 4;
  tmp.critical = 1;
  k.changeInfo(tmp);

  l = theJobs.createChild(current);
  tmp.element = "Design Utilities";
  tmp.duration = 2;
  tmp.critical = 1;
  l.changeInfo(tmp);

  m = theJobs.createChild(current);
  tmp.element = "Design Driver";
  tmp.duration = 4;
  tmp.critical = 1;
  m.changeInfo(tmp);

  n = theJobs.createChild(current);
  tmp.element = "Get Dept Report";
  tmp.duration = 1;
  tmp.critical = 0;
  n.changeInfo(tmp);

  o = theJobs.createChild(current);
  tmp.element = "Design Protocol";
  tmp.duration = 4;
  tmp.critical = 1;
  o.changeInfo(tmp);

  p = theJobs.createChild(current);
  tmp.element = "Design I/O";
  tmp.duration = 3;
  tmp.critical = 0;
  p.changeInfo(tmp);

}

void calcCompletion (TreeItr Top)
{
if(Top.hasChild())
{
  Top.advanceChild();

    while(!Top.isPast())
      {
        postorderPrint(Top);
        cTime=cTime + Top.getInfo().duration;
        Top.advanceSibling();
      }
}

}
void determineCritical(TreeItr Top)
{
  if(Top.getInfo().critical)
    cout<<" Critical ";
  else
    cout<<" Not Critical ";
}

void postorderPrint(TreeItr p)
{
  if(p.hasChild())
  {
    p.advanceChild();

      while(!p.isPast())
        {
          postorderPrint(p);
          cout<< p.getInfo().element<<" ";
          determineCritical(p);
        cout<<p.getInfo().duration<<endl;
          p.advanceSibling();
        }
  }
}
