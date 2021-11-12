#include <iostream>
#include <climits>

//data structure
/**
 * @brief elements for storing data for each boxes type
 * 
 */
struct boxes_type {
    long int XL{};
    long int L{};
    long int M{};
    long int S{};
    };

//function prototypes:
//step 1
/**
 * @brief Get the total parts to be placed in the boxes. How many parts in total?  
 * @return unsigned int as the number of parts entered by the user 
 */

unsigned int get_total_parts();//prototype

//step 2

/**
 * @brief Get the total boxes object
 * @param b_tot 
 */
void get_total_boxes(boxes_type& b_tot);

/**
 * @brief To get the limit of parts in each boxes
 * @param b_siz 
 */
void get_sizeof_boxes(boxes_type& b_siz);


/**
 * @brief The function with all the correct filling algorithms
 * @param b_tot 
 * @param b_siz 
 * @param N 
 */
void fill_up_boxes(const boxes_type& b_tot, const boxes_type& b_siz, const int& N);





//function definitions
unsigned int get_total_parts()
    {
        int a;
        int b = 0;
        std::string s; //variable to store the number entered by the user in string format.

        //Prompt the user to enter an integer.
        std::cout << "How many parts in total? ";
        std::getline(std::cin>>std::ws, s);

        a = s.length();





    /**
     * @brief checking ascii code for correct type of input
     * 
     */
        for (int i=0;i<a;i++)

           {    
                if(int(s[i]<48) || int(s[i]>57) || stol(s)<0 || stod(s)>UINT_MAX)   
                     {
                        std::cout << "How many total parts in total: (only integer please!)";
                        std::getline(std::cin>>std::ws, s);
                        a = s.length();
                        i=0;
                        continue;
                     }
      
    
            }
          b = stoi(s);

        
          return b;
         
    }


void get_total_boxes(boxes_type& b_tot)
    {
          
        int a{-1}; 
long int S{-1};
long int M{-1};
long int L{-1};
long int XL{-1}; 
int s_1 =1;
int s_2 =1;
int s_3 = 1; 
//int s_4 = 0;

std::string s; //variable to store the number entered by the user.
std::string::size_type s_r, m_r, l_r, xl_r, sub_m, sub_l, sub_xl;

//Prompt the user to enter an integer.
std::cout << "How many boxes S/M/L/XL? (Enter a positive integer value with proper space) ";
std::getline(std::cin>>std::ws, s);

a = s.length();




do{
    

for (int i=0;i<a;i++)

{    //std::cout<<"new a is"<<a<<std::endl;
    if(int(s[i]<48) || int(s[i]>57) || s_1==0 || s_2 ==0 || s_3 == 0 )  //checking for only integer numbers using ascii code and no entries
    {
        if(s[i]==32)
        {
            continue;   //spaces are okay
        }
        else
        {

          
        std::cout << "Enter only positive integer values: (S/M/L/XL)  " ;
        std::getline(std::cin>>std::ws, s);
        a = s.length();
        i=0;
        s_1 =1;
        s_2 =1;
        s_3 = 1;
        continue;
        }
        
    }

      
    
    
    
}

        S = stol(s, &s_r);                                      //conversion of string to integer
        s_1 = s.substr(s_r).length();
        //std::cout<<"s_1 is"<<s_1<<std::endl;
        if(s_1>1)                                              //check if there is something other than first integer input
        {
        //std::cout<<"remaining value is: "<<s.substr(s_r);
        M = stol(s.substr(s_r), &m_r);
        s_2 = s.substr(s_r).substr(m_r).length();
        //std::cout<<"s_2 is"<<s_2<<std::endl;
          if(s_2>1)
             {
                 //std::cout<<"remaining value is: "<<s.substr(s_r).substr(m_r);
                 L = stol(s.substr(s_r).substr(m_r), &l_r);
                 s_3 = s.substr(s_r).substr(m_r).substr(l_r).length();
                 //std::cout<<"s_3 is"<<s_3<<std::endl;
                   if(s_3>1)
                        {
                          //std::cout<<"remaining value is: "<<s.substr(s_r).length();
                           XL = stol(s.substr(s_r).substr(m_r).substr(l_r), &xl_r);
                        }            
              }    
        }
  
 
 
 b_tot.S = S;    //putting the values in struct objects called 
 b_tot.M = M;
 b_tot.L = L;
 b_tot.XL = XL;
}
while(s_1<1 || s_2 <1 || s_3 < 0 || b_tot.S<0 || b_tot.S>UINT_MAX || b_tot.M<0 || b_tot.M>UINT_MAX|| b_tot.L<0 || b_tot.L>UINT_MAX|| b_tot.XL<0 || b_tot.XL>UINT_MAX ); //all required conditions like maximum integer size
        
        
        
        
      
    }

    void get_sizeof_boxes(boxes_type& b_siz)
     { 
        
                   
          
               
        
        
        int i = 0;
        do
        {
            if(i>0)
            {
            std::cin.clear();
            std::cin.ignore(256,'\n');
           }
            std::cout<<"How many parts per box for S/M/L/XL? (XL>L>M>S)";    //prompt the user to enter values
                                             
            std::cin>>b_siz.S>>b_siz.M>>b_siz.L>>b_siz.XL;
            std::cout<<std::endl;
            i++;
        }
        while(b_siz.S<0 || b_siz.S>UINT_MAX || b_siz.M<0 || b_siz.M>UINT_MAX || b_siz.L<0 || b_siz.L>UINT_MAX || b_siz.XL<0 || b_siz.XL>UINT_MAX || 
        b_siz.S>=b_siz.M || b_siz.M>=b_siz.L || b_siz.L>=b_siz.XL ||std::cin.fail());   //checked for size of boxes and integer limit
    }


    void fill_up_boxes(const boxes_type& b_tot, const boxes_type& b_siz, const int& N)

    {
        
            int filled_XL{0};     //temporary variables to perform operations
            int filled_L{0};
            int filled_M{0};
            int filled_S{0};
            int tot_rem_XL{N};
            int tot_rem_L{0}; 
            int tot_rem_M{0}; 
            int tot_rem_S{0};
            int XL_Boxes = b_tot.XL;
            int L_Boxes = b_tot.L;
            int M_Boxes = b_tot.M;
            int S_Boxes = b_tot.S;

            while(XL_Boxes>0 && tot_rem_XL>0 && (tot_rem_XL/b_siz.XL>0))   //check whether we can use XL box or not considering size and no. of parts
            {
                filled_XL++;
                XL_Boxes--;
                tot_rem_XL = N-(filled_XL*b_siz.XL);
                                
            }

            /**
             * @brief remaining boxes assigned to new variable
             * 
             */
            tot_rem_L=tot_rem_XL;  
            
            while(L_Boxes>0 && tot_rem_L>0 && (tot_rem_L/b_siz.L>0)) //check whether we can use L box or not considering size and no. of parts
            {
                filled_L++;
                L_Boxes--;
                tot_rem_L = tot_rem_XL-(filled_L*b_siz.L);
            }

                  
            
              tot_rem_M = tot_rem_L;
              
              while(M_Boxes>0 && tot_rem_M>0 && (tot_rem_M/b_siz.M>0)) //check whether we can use M box or not considering size and no. of parts
            {
                filled_M++;
                M_Boxes--;
                tot_rem_M = tot_rem_L-(filled_M*b_siz.M);
                
                 
            }

                   

                        
              tot_rem_S = tot_rem_M;
              
              while(S_Boxes>0 && tot_rem_S>0 && (tot_rem_S/b_siz.S>0))   ////check whether we can use S box or not considering size and no. of parts
            {
                filled_S++;
                S_Boxes--;
                tot_rem_S = tot_rem_M-(filled_S*b_siz.S);
                
                 
            }

            std::cout<<"Boxes that can be built with "<<N<<" pegs:"<<std::endl<<"----------------------------------------------------"<<std::endl;
            std::cout<<"XL box ("<<b_tot.XL<<" X "<<b_siz.XL<<") : "<<filled_XL++<<" -- remanining parts: "<<tot_rem_XL<<std::endl;
            std::cout<<"L box ("<<b_tot.L<<" X "<<b_siz.L<<") : "<<filled_L++<<" -- remanining parts: "<<tot_rem_L<<std::endl;
            std::cout<<"M box ("<<b_tot.M<<" X "<<b_siz.M<<") : "<<filled_M++<<" -- remanining parts: "<<tot_rem_M<<std::endl;
            std::cout<<"S box ("<<b_tot.S<<" X "<<b_siz.S<<") : "<<filled_S++<<" -- remanining parts: "<<tot_rem_S<<std::endl;


                     

        

    }    
    


/**
 * @brief Main() includes 1 variable for storing total parts and and two structure variables to store the sizes and limits of each boxes
 * 
 * @return int 
 */
int main() 
{
    int total{};
    boxes_type b_total;
    boxes_type b_size;
    total = get_total_parts();  //function to get total parts
   
    get_total_boxes(b_total);  //function called to get no of each boxes

    get_sizeof_boxes(b_size);   //function to get size of boxes
     
    fill_up_boxes(b_total, b_size, total);  //function called to perform the algorithm required for filling the boxes and printing output

}


