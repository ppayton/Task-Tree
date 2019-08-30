
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;



       class Task
         {
           public:
            string element;
            int duration;
            int completionTime;
            bool critical;
            Task() : element(""), duration(0), completionTime(0),
                        critical(0) {};
            Task( string theString  , int theDuration ,
                  int theCompletion,
                   bool isCritical )
                 : element(theString), duration(theDuration),
                    completionTime(theCompletion),
                     critical(isCritical) {};

          };

        class TreeNode
        {
            Task info;
            TreeNode * leftChild;
            TreeNode * rightSibling;

            TreeNode() : info(), leftChild(NULL), rightSibling(NULL) {};

            TreeNode( Task theTask, TreeNode *lt, TreeNode *rt )
              : info( theTask ), leftChild( lt ), rightSibling( rt ) { }

            friend class Tree;
            friend class TreeItr;
        };

class TreeItr
        {
          public:
            TreeItr( ) : current( NULL ) { }
            bool isPast( ) const
              { return current == NULL; }
            bool hasChild( ) const
              { return current->leftChild != NULL; }
            void advanceSibling( )
              { if( !isPast( ) ) current = current->rightSibling; }
            void advanceChild( )
              { if( !isPast( ) ) current = current->leftChild; }

            Task getInfo()
              {  if( !isPast( ) ) return current->info; }

            void changeInfo( Task  x)
        	{
           	 current->info = x;
        	}

          private:
            TreeNode *current;

            TreeItr( TreeNode *theNode )
              : current( theNode ) { }

            friend class Tree;
        };

        class Tree
        {
          public:
            explicit Tree( );
            bool isEmpty( ) const;
            TreeItr createChild( TreeItr p );
            TreeItr TreeRoot( ) const;

          private:
            TreeNode *root;

        };

Tree::Tree()
{
  root = new TreeNode;
}

bool Tree::isEmpty() const
{
  return(root == NULL);
}

TreeItr Tree::createChild( TreeItr p )
{

TreeNode* newNode;
  if(!(p.current->leftChild))
    {
      p.current->leftChild =new TreeNode();
      newNode = p.current->leftChild;
    }
else
{
  newNode = new TreeNode();
  newNode->rightSibling = p.current->leftChild;
  p.current->leftChild = newNode;
}
return TreeItr(newNode);
}

TreeItr Tree::TreeRoot( ) const
{
  return TreeItr(root);
}
