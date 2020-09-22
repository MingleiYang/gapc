
// A dynamic programming evaluator generated by GAP-C.
// 
//   GAP-C version:
//     gapc
// 
//   GAP-C call:
//     gapc -p affine * pretty --backtrace --cyk affinelocsim.gap 
// 
// 


#define GAPC_MOD_TRANSLATION_UNIT
#include "out.hh"

#include <rtlib/subopt.hh>

#include <rtlib/generic_opts.hh>
#include "rtlib/pareto_dom_sort.hh"
#include "rtlib/pareto_yukish_ref.hh"

int &  out::nt_alignment(unsigned int t_0_i, unsigned int t_0_j)
{
  return alignment_table.get(t_0_i, t_0_j);
}

void out::nt_tabulate_alignment(unsigned int t_0_i, unsigned int t_0_j)
{
  int answers;
  empty(answers);
  empty( answers);
  int ret_0;
  if (((t_0_j - t_0_i) >= 0))
  {
    int ret_1 = SEQ(t_0_seq, t_0_i, t_0_j);
    int a_0 = ret_1;
    if (is_not_empty(a_0))
      {
        ret_0 = nil(a_0);
      }

    else
      {
        empty( ret_0);
      }

    erase( a_0);
  }

  else
    {
      empty( ret_0);
    }

  if (is_not_empty(ret_0))
    {
      push_back_max( answers, ret_0);
    }

  int ret_2;
  if (((t_0_j - t_0_i) >= 1))
  {
    char ret_3 = CHAR_SEP(t_0_seq, t_0_i, (t_0_i + 1));
    char a_1 = ret_3;
    if (is_not_empty(a_1))
    {
      int ret_4 = nt_xDel((t_0_i + 1), t_0_j);
      int a_2 = ret_4;
      if (is_not_empty(a_2))
        {
          ret_2 = del(a_1, a_2);
        }

      else
        {
          empty( ret_2);
        }

      erase( a_2);
    }

    else
      {
        empty( ret_2);
      }

    erase( a_1);
  }

  else
    {
      empty( ret_2);
    }

  if (is_not_empty(ret_2))
    {
      push_back_max( answers, ret_2);
    }

  int ret_5;
  if (((t_0_j - t_0_i) >= 1))
  {
    char ret_7 = CHAR_SEP(t_0_seq, (t_0_j - 1), t_0_j);
    char a_4 = ret_7;
    if (is_not_empty(a_4))
    {
      int ret_6 = nt_xIns(t_0_i, (t_0_j - 1));
      int a_3 = ret_6;
      if (is_not_empty(a_3))
        {
          ret_5 = ins(a_3, a_4);
        }

      else
        {
          empty( ret_5);
        }

      erase( a_3);
    }

    else
      {
        empty( ret_5);
      }

    erase( a_4);
  }

  else
    {
      empty( ret_5);
    }

  if (is_not_empty(ret_5))
    {
      push_back_max( answers, ret_5);
    }

  int ret_8;
  if (((t_0_j - t_0_i) >= 2))
  {
    char ret_11 = CHAR_SEP(t_0_seq, (t_0_j - 1), t_0_j);
    char a_7 = ret_11;
    if (is_not_empty(a_7))
    {
      char ret_9 = CHAR_SEP(t_0_seq, t_0_i, (t_0_i + 1));
      char a_5 = ret_9;
      if (is_not_empty(a_5))
      {
        int ret_10 = nt_alignment((t_0_i + 1), (t_0_j - 1));
        int a_6 = ret_10;
        if (is_not_empty(a_6))
          {
            ret_8 = match(a_5, a_6, a_7);
          }

        else
          {
            empty( ret_8);
          }

        erase( a_6);
      }

      else
        {
          empty( ret_8);
        }

      erase( a_5);
    }

    else
      {
        empty( ret_8);
      }

    erase( a_7);
  }

  else
    {
      empty( ret_8);
    }

  if (is_not_empty(ret_8))
    {
      push_back_max( answers, ret_8);
    }

  int eval = h(answers);
  erase( answers);
  alignment_table.set( t_0_i, t_0_j, eval);
  return;
}

int out::nt_skipL(unsigned int t_0_i, unsigned int t_0_j)
{
  int answers;
  empty(answers);
  empty( answers);
  int ret_0;
  if (((t_0_j - t_0_i) >= 1))
  {
    char ret_1 = CHAR_SEP(t_0_seq, t_0_i, (t_0_i + 1));
    char a_0 = ret_1;
    if (is_not_empty(a_0))
    {
      int ret_2 = nt_skipL((t_0_i + 1), t_0_j);
      int a_1 = ret_2;
      if (is_not_empty(a_1))
        {
          ret_0 = sl(a_0, a_1);
        }

      else
        {
          empty( ret_0);
        }

      erase( a_1);
    }

    else
      {
        empty( ret_0);
      }

    erase( a_0);
  }

  else
    {
      empty( ret_0);
    }

  if (is_not_empty(ret_0))
    {
      push_back_max( answers, ret_0);
    }

  int ret_3 = nt_alignment(t_0_i, t_0_j);
  if (is_not_empty(ret_3))
    {
      push_back_max( answers, ret_3);
    }

  int eval = h(answers);
  erase( answers);
  return eval;
}

int out::nt_skipR(unsigned int t_0_j)
{
  int answers;
  empty(answers);
  empty( answers);
  int ret_0;
  if (((t_0_j - t_0_left_most) >= 1))
  {
    char ret_2 = CHAR_SEP(t_0_seq, (t_0_j - 1), t_0_j);
    char a_1 = ret_2;
    if (is_not_empty(a_1))
    {
      int ret_1 = nt_skipR((t_0_j - 1));
      int a_0 = ret_1;
      if (is_not_empty(a_0))
        {
          ret_0 = sr(a_0, a_1);
        }

      else
        {
          empty( ret_0);
        }

      erase( a_0);
    }

    else
      {
        empty( ret_0);
      }

    erase( a_1);
  }

  else
    {
      empty( ret_0);
    }

  if (is_not_empty(ret_0))
    {
      push_back_max( answers, ret_0);
    }

  int ret_3 = nt_skipL(t_0_left_most, t_0_j);
  if (is_not_empty(ret_3))
    {
      push_back_max( answers, ret_3);
    }

  int eval = h(answers);
  erase( answers);
  return eval;
}

int &  out::nt_xDel(unsigned int t_0_i, unsigned int t_0_j)
{
  return xDel_table.get(t_0_i, t_0_j);
}

void out::nt_tabulate_xDel(unsigned int t_0_i, unsigned int t_0_j)
{
  int answers;
  empty(answers);
  empty( answers);
  int ret_0 = nt_alignment(t_0_i, t_0_j);
  if (is_not_empty(ret_0))
    {
      push_back_max( answers, ret_0);
    }

  int ret_1;
  if (((t_0_j - t_0_i) >= 1))
  {
    char ret_2 = CHAR_SEP(t_0_seq, t_0_i, (t_0_i + 1));
    char a_0 = ret_2;
    if (is_not_empty(a_0))
    {
      int ret_3 = nt_xDel((t_0_i + 1), t_0_j);
      int a_1 = ret_3;
      if (is_not_empty(a_1))
        {
          ret_1 = delx(a_0, a_1);
        }

      else
        {
          empty( ret_1);
        }

      erase( a_1);
    }

    else
      {
        empty( ret_1);
      }

    erase( a_0);
  }

  else
    {
      empty( ret_1);
    }

  if (is_not_empty(ret_1))
    {
      push_back_max( answers, ret_1);
    }

  int eval = h(answers);
  erase( answers);
  xDel_table.set( t_0_i, t_0_j, eval);
  return;
}

int &  out::nt_xIns(unsigned int t_0_i, unsigned int t_0_j)
{
  return xIns_table.get(t_0_i, t_0_j);
}

void out::nt_tabulate_xIns(unsigned int t_0_i, unsigned int t_0_j)
{
  int answers;
  empty(answers);
  empty( answers);
  int ret_0 = nt_alignment(t_0_i, t_0_j);
  if (is_not_empty(ret_0))
    {
      push_back_max( answers, ret_0);
    }

  int ret_1;
  if (((t_0_j - t_0_i) >= 1))
  {
    char ret_3 = CHAR_SEP(t_0_seq, (t_0_j - 1), t_0_j);
    char a_1 = ret_3;
    if (is_not_empty(a_1))
    {
      int ret_2 = nt_xIns(t_0_i, (t_0_j - 1));
      int a_0 = ret_2;
      if (is_not_empty(a_0))
        {
          ret_1 = insx(a_0, a_1);
        }

      else
        {
          empty( ret_1);
        }

      erase( a_0);
    }

    else
      {
        empty( ret_1);
      }

    erase( a_1);
  }

  else
    {
      empty( ret_1);
    }

  if (is_not_empty(ret_1))
    {
      push_back_max( answers, ret_1);
    }

  int eval = h(answers);
  erase( answers);
  xIns_table.set( t_0_i, t_0_j, eval);
  return;
}


int out::del(char a, int m)
{
#line 106 "affinelocsim.gap"
  return ((m - 15) - 1);
#line 440 "out.cc"
}

int out::delx(char a, int m)
{
#line 116 "affinelocsim.gap"
  return (m - 1);
#line 447 "out.cc"
}

int out::h(int l)
{
  return l;
  return maximum(l);
}

int out::ins(int m, char b)
{
#line 111 "affinelocsim.gap"
  return ((m - 15) - 1);
#line 460 "out.cc"
}

int out::insx(int m, char b)
{
#line 121 "affinelocsim.gap"
  return (m - 1);
#line 467 "out.cc"
}

int out::match(char a, int m, char b)
{
#line 98 "affinelocsim.gap"
  if ((a == b))
    {
      return (m + 4);
    }

  else
    {
      return (m - 3);
    }

#line 483 "out.cc"
}

int out::nil(int l)
{
#line 127 "affinelocsim.gap"
  return 0;
#line 490 "out.cc"
}

int out::sl(char a, int m)
{
#line 132 "affinelocsim.gap"
  return m;
#line 497 "out.cc"
}

int out::sr(int m, char b)
{
#line 137 "affinelocsim.gap"
  return m;
#line 504 "out.cc"
}


    void out::cyk()
{
#ifndef _OPENMP
unsigned int t_0_n = t_0_seq.size();

for (unsigned int t_0_j = 0; t_0_j < t_0_n; ++t_0_j) {
  for (unsigned int t_0_i = t_0_j + 1; t_0_i > 1; t_0_i--) {
nt_tabulate_alignment(t_0_i-1, t_0_j);
nt_tabulate_xDel(t_0_i-1, t_0_j);
nt_tabulate_xIns(t_0_i-1, t_0_j);
}

unsigned int t_0_i = 1;
nt_tabulate_alignment(t_0_i-1, t_0_j);
nt_tabulate_xDel(t_0_i-1, t_0_j);
nt_tabulate_xIns(t_0_i-1, t_0_j);
}

unsigned int t_0_j = t_0_n;
  for (unsigned int t_0_i = t_0_j + 1; t_0_i > 1; t_0_i--) {
nt_tabulate_alignment(t_0_i-1, t_0_j);
nt_tabulate_xDel(t_0_i-1, t_0_j);
nt_tabulate_xIns(t_0_i-1, t_0_j);
}

unsigned int t_0_i = 1;
nt_tabulate_alignment(t_0_i-1, t_0_j);
nt_tabulate_xDel(t_0_i-1, t_0_j);
nt_tabulate_xIns(t_0_i-1, t_0_j);
#else
  #pragma omp parallel
  {
  unsigned int n = t_0_seq.size();
  unsigned int tile_size = 32;
#ifdef TILE_SIZE
  tile_size = TILE_SIZE;
#endif
  assert(tile_size);
  unsigned int max_tiles = n / tile_size;
  int max_tiles_n = max_tiles * tile_size;
  #pragma omp for
  // OPENMP < 3 requires signed int here ...
  for (int z = 0; z < max_tiles_n; z+=tile_size)
    for (unsigned int t_0_j = z; t_0_j < z + tile_size; ++t_0_j)
      for (int t_0_i = t_0_j + 1; t_0_i > z; --t_0_i) {
nt_tabulate_alignment(t_0_i-1, t_0_j);
nt_tabulate_xDel(t_0_i-1, t_0_j);
nt_tabulate_xIns(t_0_i-1, t_0_j);
      }

  for (int z = tile_size; z < max_tiles_n; z+=tile_size)
    #pragma omp for
    for (int y = z; y < max_tiles_n; y+=tile_size) {
      unsigned int x = y - z + tile_size;
      for (unsigned int t_0_j = y; t_0_j < y + tile_size; ++t_0_j)
        for (unsigned int t_0_i = x - 1 + 1; t_0_i > x - tile_size; --t_0_i) {
nt_tabulate_alignment(t_0_i-1, t_0_j);
nt_tabulate_xDel(t_0_i-1, t_0_j);
nt_tabulate_xIns(t_0_i-1, t_0_j);
        }
    }

  } // end parallel
  unsigned int n = t_0_seq.size();
  unsigned int tile_size = 32;
#ifdef TILE_SIZE
  tile_size = TILE_SIZE;
#endif
  assert(tile_size);
  unsigned int max_tiles = n / tile_size;
  int max_tiles_n = max_tiles * tile_size;
  for (unsigned int t_0_j = max_tiles_n; t_0_j <= n; ++t_0_j)
    for (unsigned int t_0_i=t_0_j+1; t_0_i > 0; --t_0_i) {
nt_tabulate_alignment(t_0_i-1, t_0_j);
nt_tabulate_xDel(t_0_i-1, t_0_j);
nt_tabulate_xIns(t_0_i-1, t_0_j);
    }
#endif

}





#ident "$Id: Compiled with gapc gapc $"

List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > out::bt_proxy_nt_skipR(unsigned int t_0_j)
{
  List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > l;
  empty(l);
  std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  ret;
  ret.first = nt_skipR(t_0_j);
  if (isEmpty(ret.first))
    {
      empty( ret.second);
    }

  else
  {
    ret.second = new Backtrace_nt_skipR<out, spair, unsigned int> (this, t_0_j);
    push_back_max_other( l, ret);
  }

  return l;
}

List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > out::bt_proxy_nt_skipL(unsigned int t_0_i, unsigned int t_0_j)
{
  List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > l;
  empty(l);
  std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  ret;
  ret.first = nt_skipL(t_0_i, t_0_j);
  if (isEmpty(ret.first))
    {
      empty( ret.second);
    }

  else
  {
    ret.second = new Backtrace_nt_skipL<out, spair, unsigned int> (this, t_0_i, t_0_j);
    push_back_max_other( l, ret);
  }

  return l;
}

List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > out::bt_proxy_nt_alignment(unsigned int t_0_i, unsigned int t_0_j)
{
  List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > l;
  empty(l);
  std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  ret;
  ret.first = nt_alignment(t_0_i, t_0_j);
  if (isEmpty(ret.first))
    {
      empty( ret.second);
    }

  else
  {
    ret.second = new Backtrace_nt_alignment<out, spair, unsigned int> (this, t_0_i, t_0_j);
    push_back_max_other( l, ret);
  }

  return l;
}

List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > out::bt_proxy_nt_xDel(unsigned int t_0_i, unsigned int t_0_j)
{
  List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > l;
  empty(l);
  std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  ret;
  ret.first = nt_xDel(t_0_i, t_0_j);
  if (isEmpty(ret.first))
    {
      empty( ret.second);
    }

  else
  {
    ret.second = new Backtrace_nt_xDel<out, spair, unsigned int> (this, t_0_i, t_0_j);
    push_back_max_other( l, ret);
  }

  return l;
}

List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > out::bt_proxy_nt_xIns(unsigned int t_0_i, unsigned int t_0_j)
{
  List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > l;
  empty(l);
  std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  ret;
  ret.first = nt_xIns(t_0_i, t_0_j);
  if (isEmpty(ret.first))
    {
      empty( ret.second);
    }

  else
  {
    ret.second = new Backtrace_nt_xIns<out, spair, unsigned int> (this, t_0_i, t_0_j);
    push_back_max_other( l, ret);
  }

  return l;
}

intrusive_ptr<Backtrace<spair, unsigned int> >  out::bt_nt_alignment(unsigned int t_0_i, unsigned int t_0_j)
{
  List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > answers;
  empty(answers);
  empty( answers);
  std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  ret_0;
  if (((t_0_j - t_0_i) >= 0))
  {
    int ret_1 = SEQ(t_0_seq, t_0_i, t_0_j);
    int a_0 = ret_1;
    if (is_not_empty(a_0))
      {
        ret_0 = nil_bt(a_0);
      }

    else
      {
        empty( ret_0);
      }

    erase( a_0);
  }

  else
    {
      empty( ret_0);
    }

  if (is_not_empty(ret_0))
    {
      push_back_max_other( answers, ret_0);
    }


  if (((t_0_j - t_0_i) >= 1))
  {
    char ret_3 = CHAR_SEP(t_0_seq, t_0_i, (t_0_i + 1));
    char a_1 = ret_3;
    if (is_not_empty(a_1))
    {
      List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > ret_4 = bt_proxy_nt_xDel((t_0_i + 1), t_0_j);
      List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > a_2 = ret_4;
      if (is_not_empty(a_2))
        {
          for (List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > >::iterator x_2_itr = a_2.ref().begin(); x_2_itr!=a_2.ref().end(); ++x_2_itr){
            std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  x_2 = *x_2_itr;
            std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  ans = del_bt(a_1, x_2);
            push_back_max_other( answers, ans);
          }
        }

      erase( a_2);
    }

    erase( a_1);
  }


  if (((t_0_j - t_0_i) >= 1))
  {
    char ret_7 = CHAR_SEP(t_0_seq, (t_0_j - 1), t_0_j);
    char a_4 = ret_7;
    if (is_not_empty(a_4))
    {
      List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > ret_6 = bt_proxy_nt_xIns(t_0_i, (t_0_j - 1));
      List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > a_3 = ret_6;
      if (is_not_empty(a_3))
        {
          for (List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > >::iterator x_3_itr = a_3.ref().begin(); x_3_itr!=a_3.ref().end(); ++x_3_itr){
            std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  x_3 = *x_3_itr;
            std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  ans = ins_bt(x_3, a_4);
            push_back_max_other( answers, ans);
          }
        }

      erase( a_3);
    }

    erase( a_4);
  }


  if (((t_0_j - t_0_i) >= 2))
  {
    char ret_11 = CHAR_SEP(t_0_seq, (t_0_j - 1), t_0_j);
    char a_7 = ret_11;
    if (is_not_empty(a_7))
    {
      char ret_9 = CHAR_SEP(t_0_seq, t_0_i, (t_0_i + 1));
      char a_5 = ret_9;
      if (is_not_empty(a_5))
      {
        List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > ret_10 = bt_proxy_nt_alignment((t_0_i + 1), (t_0_j - 1));
        List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > a_6 = ret_10;
        if (is_not_empty(a_6))
          {
            for (List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > >::iterator x_6_itr = a_6.ref().begin(); x_6_itr!=a_6.ref().end(); ++x_6_itr){
              std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  x_6 = *x_6_itr;
              std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  ans = match_bt(a_5, x_6, a_7);
              push_back_max_other( answers, ans);
            }
          }

        erase( a_6);
      }

      erase( a_5);
    }

    erase( a_7);
  }

  List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > eval = h_bt(answers, alignment_table.get(t_0_i, t_0_j));
  erase( answers);
  intrusive_ptr<Backtrace<spair, unsigned int> >  bt_list = execute_backtrack(eval);
  erase( eval);
  return bt_list;
}

intrusive_ptr<Backtrace<spair, unsigned int> >  out::bt_nt_skipL(unsigned int t_0_i, unsigned int t_0_j)
{
  List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > answers;
  empty(answers);
  empty( answers);

  if (((t_0_j - t_0_i) >= 1))
  {
    char ret_1 = CHAR_SEP(t_0_seq, t_0_i, (t_0_i + 1));
    char a_0 = ret_1;
    if (is_not_empty(a_0))
    {
      List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > ret_2 = bt_proxy_nt_skipL((t_0_i + 1), t_0_j);
      List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > a_1 = ret_2;
      if (is_not_empty(a_1))
        {
          for (List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > >::iterator x_1_itr = a_1.ref().begin(); x_1_itr!=a_1.ref().end(); ++x_1_itr){
            std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  x_1 = *x_1_itr;
            std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  ans = sl_bt(a_0, x_1);
            push_back_max_other( answers, ans);
          }
        }

      erase( a_1);
    }

    erase( a_0);
  }

  List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > ret_3 = bt_proxy_nt_alignment(t_0_i, t_0_j);
  append_max_other( answers, ret_3);
  List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > eval = h_bt(answers);
  erase( answers);
  intrusive_ptr<Backtrace<spair, unsigned int> >  bt_list = execute_backtrack(eval);
  erase( eval);
  return bt_list;
}

intrusive_ptr<Backtrace<spair, unsigned int> >  out::bt_nt_skipR(unsigned int t_0_j)
{
  List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > answers;
  empty(answers);
  empty( answers);

  if (((t_0_j - t_0_left_most) >= 1))
  {
    char ret_2 = CHAR_SEP(t_0_seq, (t_0_j - 1), t_0_j);
    char a_1 = ret_2;
    if (is_not_empty(a_1))
    {
      List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > ret_1 = bt_proxy_nt_skipR((t_0_j - 1));
      List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > a_0 = ret_1;
      if (is_not_empty(a_0))
        {
          for (List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > >::iterator x_0_itr = a_0.ref().begin(); x_0_itr!=a_0.ref().end(); ++x_0_itr){
            std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  x_0 = *x_0_itr;
            std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  ans = sr_bt(x_0, a_1);
            push_back_max_other( answers, ans);
          }
        }

      erase( a_0);
    }

    erase( a_1);
  }

  List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > ret_3 = bt_proxy_nt_skipL(t_0_left_most, t_0_j);
  append_max_other( answers, ret_3);
  List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > eval = h_bt(answers);
  erase( answers);
  intrusive_ptr<Backtrace<spair, unsigned int> >  bt_list = execute_backtrack(eval);
  erase( eval);
  return bt_list;
}

intrusive_ptr<Backtrace<spair, unsigned int> >  out::bt_nt_xDel(unsigned int t_0_i, unsigned int t_0_j)
{
  List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > answers;
  empty(answers);
  empty( answers);
  List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > ret_0 = bt_proxy_nt_alignment(t_0_i, t_0_j);
  append_max_other( answers, ret_0);

  if (((t_0_j - t_0_i) >= 1))
  {
    char ret_2 = CHAR_SEP(t_0_seq, t_0_i, (t_0_i + 1));
    char a_0 = ret_2;
    if (is_not_empty(a_0))
    {
      List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > ret_3 = bt_proxy_nt_xDel((t_0_i + 1), t_0_j);
      List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > a_1 = ret_3;
      if (is_not_empty(a_1))
        {
          for (List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > >::iterator x_1_itr = a_1.ref().begin(); x_1_itr!=a_1.ref().end(); ++x_1_itr){
            std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  x_1 = *x_1_itr;
            std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  ans = delx_bt(a_0, x_1);
            push_back_max_other( answers, ans);
          }
        }

      erase( a_1);
    }

    erase( a_0);
  }

  List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > eval = h_bt(answers, xDel_table.get(t_0_i, t_0_j));
  erase( answers);
  intrusive_ptr<Backtrace<spair, unsigned int> >  bt_list = execute_backtrack(eval);
  erase( eval);
  return bt_list;
}

intrusive_ptr<Backtrace<spair, unsigned int> >  out::bt_nt_xIns(unsigned int t_0_i, unsigned int t_0_j)
{
  List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > answers;
  empty(answers);
  empty( answers);
  List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > ret_0 = bt_proxy_nt_alignment(t_0_i, t_0_j);
  append_max_other( answers, ret_0);

  if (((t_0_j - t_0_i) >= 1))
  {
    char ret_3 = CHAR_SEP(t_0_seq, (t_0_j - 1), t_0_j);
    char a_1 = ret_3;
    if (is_not_empty(a_1))
    {
      List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > ret_2 = bt_proxy_nt_xIns(t_0_i, (t_0_j - 1));
      List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > a_0 = ret_2;
      if (is_not_empty(a_0))
        {
          for (List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > >::iterator x_0_itr = a_0.ref().begin(); x_0_itr!=a_0.ref().end(); ++x_0_itr){
            std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  x_0 = *x_0_itr;
            std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  ans = insx_bt(x_0, a_1);
            push_back_max_other( answers, ans);
          }
        }

      erase( a_0);
    }

    erase( a_1);
  }

  List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > eval = h_bt(answers, xIns_table.get(t_0_i, t_0_j));
  erase( answers);
  intrusive_ptr<Backtrace<spair, unsigned int> >  bt_list = execute_backtrack(eval);
  erase( eval);
  return bt_list;
}


intrusive_ptr<Backtrace<spair, unsigned int> >  out::del_bt_r(char param_0, intrusive_ptr<Backtrace<spair, unsigned int> >  param_1)
{
  return new Backtrace_del<spair, unsigned int> (param_0, param_1);
}

intrusive_ptr<Backtrace<spair, unsigned int> >  out::delx_bt_r(char param_0, intrusive_ptr<Backtrace<spair, unsigned int> >  param_1)
{
  return new Backtrace_delx<spair, unsigned int> (param_0, param_1);
}

List_Ref<intrusive_ptr<Backtrace<spair, unsigned int> > > out::h_bt_r(List_Ref<intrusive_ptr<Backtrace<spair, unsigned int> > > param_0)
{
  return param_0;
}

intrusive_ptr<Backtrace<spair, unsigned int> >  out::ins_bt_r(intrusive_ptr<Backtrace<spair, unsigned int> >  param_0, char param_1)
{
  return new Backtrace_ins<spair, unsigned int> (param_0, param_1);
}

intrusive_ptr<Backtrace<spair, unsigned int> >  out::insx_bt_r(intrusive_ptr<Backtrace<spair, unsigned int> >  param_0, char param_1)
{
  return new Backtrace_insx<spair, unsigned int> (param_0, param_1);
}

intrusive_ptr<Backtrace<spair, unsigned int> >  out::match_bt_r(char param_0, intrusive_ptr<Backtrace<spair, unsigned int> >  param_1, char param_2)
{
  return new Backtrace_match<spair, unsigned int> (param_0, param_1, param_2);
}

intrusive_ptr<Backtrace<spair, unsigned int> >  out::nil_bt_r(int param_0)
{
  return new Backtrace_nil<spair, unsigned int> (param_0);
}

intrusive_ptr<Backtrace<spair, unsigned int> >  out::sl_bt_r(char param_0, intrusive_ptr<Backtrace<spair, unsigned int> >  param_1)
{
  return new Backtrace_sl<spair, unsigned int> (param_0, param_1);
}

intrusive_ptr<Backtrace<spair, unsigned int> >  out::sr_bt_r(intrusive_ptr<Backtrace<spair, unsigned int> >  param_0, char param_1)
{
  return new Backtrace_sr<spair, unsigned int> (param_0, param_1);
}



std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  out::del_bt(char p_a, const std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > & p_m)
{
  char l_0 = p_a;
  int l_1 = p_m.first;
  char r_0 = p_a;
  intrusive_ptr<Backtrace<spair, unsigned int> >  r_1 = p_m.second;
  int ret_left = del(l_0, l_1);
  intrusive_ptr<Backtrace<spair, unsigned int> >  ret_right = del_bt_r(r_0, r_1);
  std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  ret;
  ret.first = ret_left;
  ret.second = ret_right;
  return ret;
}

std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  out::delx_bt(char p_a, const std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > & p_m)
{
  char l_0 = p_a;
  int l_1 = p_m.first;
  char r_0 = p_a;
  intrusive_ptr<Backtrace<spair, unsigned int> >  r_1 = p_m.second;
  int ret_left = delx(l_0, l_1);
  intrusive_ptr<Backtrace<spair, unsigned int> >  ret_right = delx_bt_r(r_0, r_1);
  std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  ret;
  ret.first = ret_left;
  ret.second = ret_right;
  return ret;
}

List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > out::h_bt(List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > l, int &  left)
{
  return l;
}

List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > out::h_bt(List_Ref<std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > > l)
{
  return l;
}

std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  out::ins_bt(const std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > & p_m, char p_b)
{
  int l_0 = p_m.first;
  char l_1 = p_b;
  intrusive_ptr<Backtrace<spair, unsigned int> >  r_0 = p_m.second;
  char r_1 = p_b;
  int ret_left = ins(l_0, l_1);
  intrusive_ptr<Backtrace<spair, unsigned int> >  ret_right = ins_bt_r(r_0, r_1);
  std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  ret;
  ret.first = ret_left;
  ret.second = ret_right;
  return ret;
}

std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  out::insx_bt(const std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > & p_m, char p_b)
{
  int l_0 = p_m.first;
  char l_1 = p_b;
  intrusive_ptr<Backtrace<spair, unsigned int> >  r_0 = p_m.second;
  char r_1 = p_b;
  int ret_left = insx(l_0, l_1);
  intrusive_ptr<Backtrace<spair, unsigned int> >  ret_right = insx_bt_r(r_0, r_1);
  std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  ret;
  ret.first = ret_left;
  ret.second = ret_right;
  return ret;
}

std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  out::match_bt(char p_a, const std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > & p_m, char p_b)
{
  char l_0 = p_a;
  int l_1 = p_m.first;
  char l_2 = p_b;
  char r_0 = p_a;
  intrusive_ptr<Backtrace<spair, unsigned int> >  r_1 = p_m.second;
  char r_2 = p_b;
  int ret_left = match(l_0, l_1, l_2);
  intrusive_ptr<Backtrace<spair, unsigned int> >  ret_right = match_bt_r(r_0, r_1, r_2);
  std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  ret;
  ret.first = ret_left;
  ret.second = ret_right;
  return ret;
}

std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  out::nil_bt(int p_l)
{
  int l_0 = p_l;
  int r_0 = p_l;
  int ret_left = nil(l_0);
  intrusive_ptr<Backtrace<spair, unsigned int> >  ret_right = nil_bt_r(r_0);
  std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  ret;
  ret.first = ret_left;
  ret.second = ret_right;
  return ret;
}

std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  out::sl_bt(char p_a, const std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > & p_m)
{
  char l_0 = p_a;
  int l_1 = p_m.first;
  char r_0 = p_a;
  intrusive_ptr<Backtrace<spair, unsigned int> >  r_1 = p_m.second;
  int ret_left = sl(l_0, l_1);
  intrusive_ptr<Backtrace<spair, unsigned int> >  ret_right = sl_bt_r(r_0, r_1);
  std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  ret;
  ret.first = ret_left;
  ret.second = ret_right;
  return ret;
}

std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  out::sr_bt(const std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > > & p_m, char p_b)
{
  int l_0 = p_m.first;
  char l_1 = p_b;
  intrusive_ptr<Backtrace<spair, unsigned int> >  r_0 = p_m.second;
  char r_1 = p_b;
  int ret_left = sr(l_0, l_1);
  intrusive_ptr<Backtrace<spair, unsigned int> >  ret_right = sr_bt_r(r_0, r_1);
  std::pair<int, intrusive_ptr<Backtrace<spair, unsigned int> > >  ret;
  ret.first = ret_left;
  ret.second = ret_right;
  return ret;
}


