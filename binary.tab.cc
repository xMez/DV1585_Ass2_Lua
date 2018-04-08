// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "binary.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "binary.tab.hh"

// User implementation prologue.

#line 51 "binary.tab.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 8 "binary.yy" // lalr1.cc:413

	unsigned int total = 0;
	#include <string>
	#define YY_DECL yy::parser::symbol_type yylex()
	YY_DECL;
	Node root;

#line 61 "binary.tab.cc" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 128 "binary.tab.cc" // lalr1.cc:479

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
      switch (that.type_get ())
    {
      case 54: // block
      case 55: // chunk
      case 56: // optchunk
      case 57: // laststat
      case 58: // optsemi
      case 59: // stat
      case 60: // ifexp
      case 61: // optelseif
      case 62: // elseif
      case 63: // optelse
      case 64: // funcnamelist
      case 65: // funcname
      case 66: // varlist
      case 67: // var
      case 68: // namelist
      case 69: // name
      case 70: // explist
      case 71: // exp
      case 72: // prefixexp
      case 73: // functioncall
      case 74: // args
      case 75: // function
      case 76: // funcbody
      case 77: // parlist
      case 78: // tableconstructor
      case 79: // fieldlistexp
      case 80: // fieldlist
      case 81: // field
      case 82: // fieldsep
      case 83: // optfieldsep
      case 84: // string
      case 85: // ops
      case 86: // ops_1
      case 87: // ops_2
      case 88: // ops_3
      case 89: // ops_4
      case 90: // ops_5
      case 91: // ops_6
      case 92: // ops_7
      case 93: // ops_8
      case 94: // ops_9
        value.move< Node > (that.value);
        break;

      case 3: // DO
      case 4: // WHILE
      case 5: // FOR
      case 6: // UNTIL
      case 7: // REPEAT
      case 8: // END
      case 9: // IN
      case 10: // IF
      case 11: // THEN
      case 12: // ELSEIF
      case 13: // ELSE
      case 14: // PLUS
      case 15: // MIN
      case 16: // MUL
      case 17: // DIV
      case 18: // POW
      case 19: // MOD
      case 20: // EQUAL
      case 21: // LESS_THAN
      case 22: // MORE_THAN
      case 23: // LESS_EQUAL_THAN
      case 24: // MORE_EQUAL_THAN
      case 25: // TILDE_EQUAL
      case 26: // CONCAT
      case 27: // AND
      case 28: // OR
      case 29: // LEN
      case 30: // NOT
      case 31: // LOCAL
      case 32: // FUNCTION
      case 33: // RETURN
      case 34: // BREAK
      case 35: // NIL
      case 36: // FALSE
      case 37: // TRUE
      case 38: // NUMBER
      case 39: // STRING
      case 40: // TDOT
      case 41: // NAME
      case 42: // ASSIGN
      case 43: // DOT
      case 44: // COLON
      case 45: // COMMA
      case 46: // SEMI
      case 47: // PARA_L
      case 48: // PARA_R
      case 49: // BRACE_L
      case 50: // BRACE_R
      case 51: // BRACK_L
      case 52: // BRACK_R
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 54: // block
      case 55: // chunk
      case 56: // optchunk
      case 57: // laststat
      case 58: // optsemi
      case 59: // stat
      case 60: // ifexp
      case 61: // optelseif
      case 62: // elseif
      case 63: // optelse
      case 64: // funcnamelist
      case 65: // funcname
      case 66: // varlist
      case 67: // var
      case 68: // namelist
      case 69: // name
      case 70: // explist
      case 71: // exp
      case 72: // prefixexp
      case 73: // functioncall
      case 74: // args
      case 75: // function
      case 76: // funcbody
      case 77: // parlist
      case 78: // tableconstructor
      case 79: // fieldlistexp
      case 80: // fieldlist
      case 81: // field
      case 82: // fieldsep
      case 83: // optfieldsep
      case 84: // string
      case 85: // ops
      case 86: // ops_1
      case 87: // ops_2
      case 88: // ops_3
      case 89: // ops_4
      case 90: // ops_5
      case 91: // ops_6
      case 92: // ops_7
      case 93: // ops_8
      case 94: // ops_9
        value.copy< Node > (that.value);
        break;

      case 3: // DO
      case 4: // WHILE
      case 5: // FOR
      case 6: // UNTIL
      case 7: // REPEAT
      case 8: // END
      case 9: // IN
      case 10: // IF
      case 11: // THEN
      case 12: // ELSEIF
      case 13: // ELSE
      case 14: // PLUS
      case 15: // MIN
      case 16: // MUL
      case 17: // DIV
      case 18: // POW
      case 19: // MOD
      case 20: // EQUAL
      case 21: // LESS_THAN
      case 22: // MORE_THAN
      case 23: // LESS_EQUAL_THAN
      case 24: // MORE_EQUAL_THAN
      case 25: // TILDE_EQUAL
      case 26: // CONCAT
      case 27: // AND
      case 28: // OR
      case 29: // LEN
      case 30: // NOT
      case 31: // LOCAL
      case 32: // FUNCTION
      case 33: // RETURN
      case 34: // BREAK
      case 35: // NIL
      case 36: // FALSE
      case 37: // TRUE
      case 38: // NUMBER
      case 39: // STRING
      case 40: // TDOT
      case 41: // NAME
      case 42: // ASSIGN
      case 43: // DOT
      case 44: // COLON
      case 45: // COMMA
      case 46: // SEMI
      case 47: // PARA_L
      case 48: // PARA_R
      case 49: // BRACE_L
      case 50: // BRACE_R
      case 51: // BRACK_L
      case 52: // BRACK_R
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 54: // block
      case 55: // chunk
      case 56: // optchunk
      case 57: // laststat
      case 58: // optsemi
      case 59: // stat
      case 60: // ifexp
      case 61: // optelseif
      case 62: // elseif
      case 63: // optelse
      case 64: // funcnamelist
      case 65: // funcname
      case 66: // varlist
      case 67: // var
      case 68: // namelist
      case 69: // name
      case 70: // explist
      case 71: // exp
      case 72: // prefixexp
      case 73: // functioncall
      case 74: // args
      case 75: // function
      case 76: // funcbody
      case 77: // parlist
      case 78: // tableconstructor
      case 79: // fieldlistexp
      case 80: // fieldlist
      case 81: // field
      case 82: // fieldsep
      case 83: // optfieldsep
      case 84: // string
      case 85: // ops
      case 86: // ops_1
      case 87: // ops_2
      case 88: // ops_3
      case 89: // ops_4
      case 90: // ops_5
      case 91: // ops_6
      case 92: // ops_7
      case 93: // ops_8
      case 94: // ops_9
        yylhs.value.build< Node > ();
        break;

      case 3: // DO
      case 4: // WHILE
      case 5: // FOR
      case 6: // UNTIL
      case 7: // REPEAT
      case 8: // END
      case 9: // IN
      case 10: // IF
      case 11: // THEN
      case 12: // ELSEIF
      case 13: // ELSE
      case 14: // PLUS
      case 15: // MIN
      case 16: // MUL
      case 17: // DIV
      case 18: // POW
      case 19: // MOD
      case 20: // EQUAL
      case 21: // LESS_THAN
      case 22: // MORE_THAN
      case 23: // LESS_EQUAL_THAN
      case 24: // MORE_EQUAL_THAN
      case 25: // TILDE_EQUAL
      case 26: // CONCAT
      case 27: // AND
      case 28: // OR
      case 29: // LEN
      case 30: // NOT
      case 31: // LOCAL
      case 32: // FUNCTION
      case 33: // RETURN
      case 34: // BREAK
      case 35: // NIL
      case 36: // FALSE
      case 37: // TRUE
      case 38: // NUMBER
      case 39: // STRING
      case 40: // TDOT
      case 41: // NAME
      case 42: // ASSIGN
      case 43: // DOT
      case 44: // COLON
      case 45: // COMMA
      case 46: // SEMI
      case 47: // PARA_L
      case 48: // PARA_R
      case 49: // BRACE_L
      case 50: // BRACE_R
      case 51: // BRACK_L
      case 52: // BRACK_R
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 119 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("block", "");
          yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				  root = yylhs.value.as< Node > ();
				}
#line 747 "binary.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 127 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();
          yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 755 "binary.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 130 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 761 "binary.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 132 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("chunk", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 769 "binary.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 139 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("chunk", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
				}
#line 777 "binary.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 143 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[2].value.as< Node > ();
				  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
				}
#line 785 "binary.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 150 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("laststat", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
				}
#line 793 "binary.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 153 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("laststat", "empty"); }
#line 799 "binary.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 154 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("laststat", "empty"); }
#line 805 "binary.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 158 "binary.yy" // lalr1.cc:859
    { }
#line 811 "binary.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 164 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("stat", "ASS");
				  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 820 "binary.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 168 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 826 "binary.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 170 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("stat", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
				}
#line 834 "binary.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 174 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("stat", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
				}
#line 843 "binary.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 179 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("stat", "REP");
				  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 852 "binary.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 184 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("stat", "IF");
				  yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
				}
#line 862 "binary.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 190 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("stat", "FOR");
				  yylhs.value.as< Node > ().children.push_back(yystack_[7].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
				}
#line 873 "binary.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 197 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("stat", "FOR");
				  yylhs.value.as< Node > ().children.push_back(yystack_[9].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[7].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
				}
#line 885 "binary.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 205 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("stat", "FOR");
				  yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
				}
#line 895 "binary.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 211 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("stat", "FUNC");
				  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 904 "binary.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 216 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("stat", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 913 "binary.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 221 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("stat", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 921 "binary.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 225 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("stat", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 930 "binary.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 233 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("ifexp", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 939 "binary.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 241 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("optelseif", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 947 "binary.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 245 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 955 "binary.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 248 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("optelseif", "empty"); }
#line 961 "binary.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 253 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("elseif", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 970 "binary.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 260 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("optelse", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 978 "binary.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 263 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("optelse", "empty"); }
#line 984 "binary.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 267 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 990 "binary.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 269 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[2].value.as< Node > ();
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 998 "binary.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 275 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("funcname", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1006 "binary.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 279 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[2].value.as< Node > ();
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1014 "binary.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 286 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("varlist", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1022 "binary.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 290 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[2].value.as< Node > ();
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1030 "binary.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 296 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 1036 "binary.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 298 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("var", "bracket");
				  yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
				}
#line 1045 "binary.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 303 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[2].value.as< Node > ();
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1053 "binary.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 310 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("namelist", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1061 "binary.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 314 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[2].value.as< Node > ();
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1069 "binary.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 320 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("NAME", yystack_[0].value.as< std::string > ()); }
#line 1075 "binary.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 325 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("explist", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1083 "binary.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 329 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[2].value.as< Node > ();
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1091 "binary.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 335 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("NIL", yystack_[0].value.as< std::string > ()); }
#line 1097 "binary.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 336 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("FALSE", yystack_[0].value.as< std::string > ()); }
#line 1103 "binary.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 337 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("TRUE", yystack_[0].value.as< std::string > ()); }
#line 1109 "binary.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 338 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("NUMBER", yystack_[0].value.as< std::string > ()); }
#line 1115 "binary.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 339 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1121 "binary.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 340 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("TDOT", yystack_[0].value.as< std::string > ()); }
#line 1127 "binary.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 342 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1135 "binary.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 345 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1141 "binary.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 347 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("exp", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
          std::cout << "Table" << std::endl;
				}
#line 1150 "binary.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 351 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1156 "binary.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 355 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1162 "binary.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 356 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1168 "binary.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 357 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 1174 "binary.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 362 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("functioncall", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1183 "binary.tab.cc" // lalr1.cc:859
    break;

  case 61:
#line 367 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("functioncall", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1193 "binary.tab.cc" // lalr1.cc:859
    break;

  case 62:
#line 375 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("args", "empty"); }
#line 1199 "binary.tab.cc" // lalr1.cc:859
    break;

  case 63:
#line 376 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); }
#line 1205 "binary.tab.cc" // lalr1.cc:859
    break;

  case 64:
#line 377 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1211 "binary.tab.cc" // lalr1.cc:859
    break;

  case 65:
#line 378 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1217 "binary.tab.cc" // lalr1.cc:859
    break;

  case 66:
#line 383 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("function", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1225 "binary.tab.cc" // lalr1.cc:859
    break;

  case 67:
#line 390 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("funcbody", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
				}
#line 1234 "binary.tab.cc" // lalr1.cc:859
    break;

  case 68:
#line 395 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("funcbody", "");
				  yylhs.value.as< Node > ().children.push_back(Node("parlist", "empty"));
				  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
				}
#line 1243 "binary.tab.cc" // lalr1.cc:859
    break;

  case 69:
#line 403 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("parlist", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1251 "binary.tab.cc" // lalr1.cc:859
    break;

  case 70:
#line 407 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[2].value.as< Node > ();
				  yylhs.value.as< Node > ().children.push_back(Node("argover", ""));
				}
#line 1259 "binary.tab.cc" // lalr1.cc:859
    break;

  case 71:
#line 410 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("parlist", "tdot"); }
#line 1265 "binary.tab.cc" // lalr1.cc:859
    break;

  case 72:
#line 415 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("tableconstructor", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
				}
#line 1273 "binary.tab.cc" // lalr1.cc:859
    break;

  case 73:
#line 418 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("tableconstructor", "empty"); }
#line 1279 "binary.tab.cc" // lalr1.cc:859
    break;

  case 74:
#line 423 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();
				  //$$.children.push_back($2);
				}
#line 1287 "binary.tab.cc" // lalr1.cc:859
    break;

  case 75:
#line 430 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("fieldlist", "");
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1295 "binary.tab.cc" // lalr1.cc:859
    break;

  case 76:
#line 434 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[2].value.as< Node > ();
				  //$$.children.push_back($2);
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1304 "binary.tab.cc" // lalr1.cc:859
    break;

  case 77:
#line 442 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("field", "backet");
				  yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1313 "binary.tab.cc" // lalr1.cc:859
    break;

  case 78:
#line 447 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("field", "assign");
				  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1322 "binary.tab.cc" // lalr1.cc:859
    break;

  case 79:
#line 452 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("field", "exp");
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1330 "binary.tab.cc" // lalr1.cc:859
    break;

  case 80:
#line 458 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("fieldsep", yystack_[0].value.as< std::string > ()); }
#line 1336 "binary.tab.cc" // lalr1.cc:859
    break;

  case 81:
#line 459 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("fieldsep", yystack_[0].value.as< std::string > ()); }
#line 1342 "binary.tab.cc" // lalr1.cc:859
    break;

  case 82:
#line 463 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1348 "binary.tab.cc" // lalr1.cc:859
    break;

  case 84:
#line 467 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("string", yystack_[0].value.as< std::string > ().substr(0, yystack_[0].value.as< std::string > ().size() - 0)); }
#line 1354 "binary.tab.cc" // lalr1.cc:859
    break;

  case 85:
#line 472 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1360 "binary.tab.cc" // lalr1.cc:859
    break;

  case 86:
#line 477 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1369 "binary.tab.cc" // lalr1.cc:859
    break;

  case 87:
#line 481 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1375 "binary.tab.cc" // lalr1.cc:859
    break;

  case 88:
#line 487 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1384 "binary.tab.cc" // lalr1.cc:859
    break;

  case 89:
#line 491 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1390 "binary.tab.cc" // lalr1.cc:859
    break;

  case 90:
#line 497 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1399 "binary.tab.cc" // lalr1.cc:859
    break;

  case 91:
#line 502 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1408 "binary.tab.cc" // lalr1.cc:859
    break;

  case 92:
#line 507 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1417 "binary.tab.cc" // lalr1.cc:859
    break;

  case 93:
#line 512 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1426 "binary.tab.cc" // lalr1.cc:859
    break;

  case 94:
#line 517 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1435 "binary.tab.cc" // lalr1.cc:859
    break;

  case 95:
#line 522 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1444 "binary.tab.cc" // lalr1.cc:859
    break;

  case 96:
#line 526 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1450 "binary.tab.cc" // lalr1.cc:859
    break;

  case 97:
#line 532 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
				}
#line 1459 "binary.tab.cc" // lalr1.cc:859
    break;

  case 98:
#line 536 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1465 "binary.tab.cc" // lalr1.cc:859
    break;

  case 99:
#line 542 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1474 "binary.tab.cc" // lalr1.cc:859
    break;

  case 100:
#line 547 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1483 "binary.tab.cc" // lalr1.cc:859
    break;

  case 101:
#line 551 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1489 "binary.tab.cc" // lalr1.cc:859
    break;

  case 102:
#line 557 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1498 "binary.tab.cc" // lalr1.cc:859
    break;

  case 103:
#line 562 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1507 "binary.tab.cc" // lalr1.cc:859
    break;

  case 104:
#line 567 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1516 "binary.tab.cc" // lalr1.cc:859
    break;

  case 105:
#line 571 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1522 "binary.tab.cc" // lalr1.cc:859
    break;

  case 106:
#line 577 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("unop", yystack_[1].value.as< std::string > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1530 "binary.tab.cc" // lalr1.cc:859
    break;

  case 107:
#line 581 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("unop", yystack_[1].value.as< std::string > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1538 "binary.tab.cc" // lalr1.cc:859
    break;

  case 108:
#line 585 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("unop", yystack_[1].value.as< std::string > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				}
#line 1546 "binary.tab.cc" // lalr1.cc:859
    break;

  case 109:
#line 588 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1552 "binary.tab.cc" // lalr1.cc:859
    break;

  case 110:
#line 594 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
				  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
				}
#line 1561 "binary.tab.cc" // lalr1.cc:859
    break;

  case 111:
#line 598 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1567 "binary.tab.cc" // lalr1.cc:859
    break;

  case 112:
#line 603 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1573 "binary.tab.cc" // lalr1.cc:859
    break;


#line 1577 "binary.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -53;

  const signed char parser::yytable_ninf_ = -113;

  const short int
  parser::yypact_[] =
  {
      56,    56,   327,   -23,    56,   327,    -4,   -23,   273,   -21,
     -53,   327,    39,   206,    18,   -53,   -21,    21,     1,    38,
     -53,    26,    42,    37,   327,   327,   327,    11,   -53,   -53,
     -53,   -53,   -53,   -53,   219,   -53,    46,    26,   -53,   -53,
     -53,   -53,   -53,    44,    55,   138,    70,   129,   135,   -53,
      89,   -53,     5,    73,   124,   125,   -23,    81,   -53,    11,
      58,   -53,   -53,   -53,   134,   363,   -53,   100,   -53,   -21,
     -53,   -53,   327,   162,   -53,   327,   -11,   -23,   -23,   300,
     327,   -53,   -53,   -53,   -53,   -53,    89,    89,    89,     7,
     -53,   -53,   327,   113,    49,   114,   142,   -53,    56,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   -23,   327,   327,    56,    11,
     327,   -53,   -23,   -23,   327,   -53,   -53,   -53,   172,    56,
     -53,   177,   154,    96,   -53,    -7,   -53,   -14,   150,   -53,
      56,   159,   166,   163,   327,   -53,   -53,   -53,   246,   -53,
     213,    55,   138,    70,    70,    70,    70,    70,    70,   129,
     135,   135,   -53,   -53,   -53,   -53,     9,   -53,   179,   363,
     -53,   -53,   154,   -53,   -53,   363,    56,   -53,   -53,   -53,
     -53,   -53,   217,   153,    56,   184,    71,   -53,   -53,    56,
     327,   -53,   -53,   -53,   221,   327,   222,    19,   -53,    87,
     -53,    56,   327,   223,   224,   -53,    56,   228,   -53
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,    12,    12,
      44,     0,     0,     2,     4,     5,    12,    29,     0,    57,
      39,     0,    14,     0,     0,     0,     0,     0,    47,    48,
      49,    50,    84,    52,     0,    57,   112,    54,    58,    53,
      55,    51,    56,    85,    87,    89,    96,    98,   101,   105,
     109,   111,     0,    42,     0,   112,     0,    24,    42,     0,
      33,    35,    11,     9,    12,    45,    10,   112,     1,    12,
       3,     6,     0,    32,    27,     0,     0,     0,     0,     0,
       0,    60,    64,    65,    15,   112,   108,   107,   106,     0,
      66,    73,     0,    39,   112,     0,    83,    75,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     8,    59,     7,   112,     0,
      28,     0,    13,    57,    41,     0,    62,     0,   112,    71,
       0,    69,     0,   112,     0,    72,    80,    81,    82,    74,
       0,    86,    88,    95,    90,    91,    92,    93,    94,    97,
      99,   100,   102,   103,   104,   110,     0,    43,   112,    17,
      26,    23,    25,    36,    34,    46,     0,    31,    18,    61,
      63,    40,     0,     0,     0,     0,   112,    76,    16,     0,
       0,    30,    68,    70,     0,     0,     0,   112,    67,   112,
      21,     0,     0,     0,   112,    19,     0,     0,    20
  };

  const short int
  parser::yypgoto_[] =
  {
     -53,     6,   -53,   -53,   218,    10,   226,   -53,   -53,   167,
     -53,   -53,   -53,   -53,     0,     3,    50,   -52,    33,     2,
      16,   106,   -53,   -48,   -53,   -16,   -53,   -53,    94,   -53,
     -53,   -13,   -53,   -53,   144,   145,    65,   137,    88,    -1,
     194,   133
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,    12,    13,    14,    15,    63,    16,    17,    73,    74,
     131,    59,    60,    18,    35,    52,    20,    64,    85,    37,
      38,    81,    39,    90,   142,    40,    95,    96,    97,   148,
     149,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51
  };

  const short int
  parser::yytable_[] =
  {
      19,    19,    21,    21,    19,    82,    21,    23,    83,    57,
      54,   121,   189,    19,   114,    21,    22,    22,    10,    66,
      22,    82,   201,   132,    83,    62,    71,   137,    56,    22,
      10,   124,    32,    72,   180,    36,    11,    10,    55,    68,
      79,    65,    34,    75,    67,    84,    76,   139,    10,    98,
     115,     8,     9,    53,   124,   140,    58,    61,    89,     1,
       2,     3,   166,     4,   202,    32,     5,    94,   172,    77,
      78,   171,    99,    79,   125,    34,   133,    80,    21,   127,
     -37,   -58,   100,   -37,    93,   -58,   -58,     6,     7,     8,
       9,   -58,   141,   -58,   -79,   -79,   107,    10,    19,   -79,
      21,   122,   123,    11,   150,   128,   119,   113,    65,   162,
     163,   164,    65,   138,    22,   116,   -78,   -78,    19,    82,
      21,   -78,    83,   120,   170,   143,   115,   134,   135,    19,
     117,    21,   -77,   -77,    22,   177,   118,   -77,   -38,    58,
      19,   -38,    21,   108,   109,    22,   182,    65,   126,   168,
     169,   110,   111,    65,   112,   144,    22,   175,   101,   102,
     103,   104,   105,   106,   145,   167,   153,   154,   155,   156,
     157,   158,   173,   174,    72,   129,    19,   186,    21,   124,
      62,    94,   191,   176,    19,   178,    21,   146,   147,    19,
     194,    21,    22,   193,    10,   196,   160,   161,    93,   124,
      22,    19,   181,    21,   183,    22,    19,   203,    21,     1,
       2,     3,   207,     4,   184,   185,     5,    22,    86,    87,
      88,   188,    22,   197,   190,   192,   195,   206,   199,   198,
     200,   205,    70,   167,    24,   204,   208,     6,     7,    69,
     130,   179,   187,   151,   159,   152,   165,    10,    25,    26,
       0,    27,     0,    11,    28,    29,    30,    31,    32,    33,
      10,    24,     0,     0,     0,     0,    11,     0,    34,    91,
      92,     0,     0,     0,     0,    25,    26,     0,    27,     0,
       0,    28,    29,    30,    31,    32,    33,    10,    24,     0,
       0,     0,     0,    11,     0,    34,     0,    92,     0,     0,
       0,     0,    25,    26,     0,    27,     0,     0,    28,    29,
      30,    31,    32,    33,    10,    24,     0,     0,     0,    62,
      11,     0,    34,     0,     0,     0,     0,     0,     0,    25,
      26,     0,    27,     0,     0,    28,    29,    30,    31,    32,
      33,    10,    24,     0,     0,     0,     0,    11,   136,    34,
       0,     0,     0,     0,     0,     0,    25,    26,     0,    27,
       0,     0,    28,    29,    30,    31,    32,    33,    10,     0,
       0,     0,     0,     0,    11,     0,    34,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,  -112
  };

  const short int
  parser::yycheck_[] =
  {
       0,     1,     0,     1,     4,    21,     4,     1,    21,     6,
       4,    59,     3,    13,     9,    13,     0,     1,    41,     9,
       4,    37,     3,    75,    37,    46,    16,    79,    32,    13,
      41,    45,    39,    12,    48,     2,    47,    41,     5,     0,
      47,     8,    49,    42,    11,     8,    45,    40,    41,     3,
      45,    33,    34,     3,    45,    48,     6,     7,    47,     3,
       4,     5,   114,     7,    45,    39,    10,    34,   120,    43,
      44,   119,    28,    47,    64,    49,    76,    51,    76,    69,
      42,    39,    27,    45,    34,    43,    44,    31,    32,    33,
      34,    49,    89,    51,    45,    46,    26,    41,    98,    50,
      98,    43,    44,    47,    98,    72,    56,    18,    75,   110,
     111,   112,    79,    80,    98,    42,    45,    46,   118,   135,
     118,    50,   135,    42,   118,    92,    45,    77,    78,   129,
       6,   129,    45,    46,   118,   129,    11,    50,    42,    89,
     140,    45,   140,    14,    15,   129,   140,   114,    48,   116,
     117,    16,    17,   120,    19,    42,   140,   124,    20,    21,
      22,    23,    24,    25,    50,   115,   101,   102,   103,   104,
     105,   106,   122,   123,    12,    13,   176,   144,   176,    45,
      46,   148,   176,    11,   184,     8,   184,    45,    46,   189,
     184,   189,   176,    40,    41,   189,   108,   109,   148,    45,
     184,   201,    52,   201,    45,   189,   206,   201,   206,     3,
       4,     5,   206,     7,    48,    52,    10,   201,    24,    25,
      26,     8,   206,   190,    45,     8,    42,     3,   195,     8,
       8,     8,    14,   183,    15,   202,     8,    31,    32,    13,
      73,   135,   148,    99,   107,   100,   113,    41,    29,    30,
      -1,    32,    -1,    47,    35,    36,    37,    38,    39,    40,
      41,    15,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,
      51,    -1,    -1,    -1,    -1,    29,    30,    -1,    32,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    15,    -1,
      -1,    -1,    -1,    47,    -1,    49,    -1,    51,    -1,    -1,
      -1,    -1,    29,    30,    -1,    32,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    15,    -1,    -1,    -1,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,    32,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    15,    -1,    -1,    -1,    -1,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    32,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    49,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     4,     5,     7,    10,    31,    32,    33,    34,
      41,    47,    54,    55,    56,    57,    59,    60,    66,    67,
      69,    72,    73,    54,    15,    29,    30,    32,    35,    36,
      37,    38,    39,    40,    49,    67,    71,    72,    73,    75,
      78,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    68,    69,    54,    71,    32,    68,    69,    64,
      65,    69,    46,    58,    70,    71,    58,    71,     0,    59,
      57,    58,    12,    61,    62,    42,    45,    43,    44,    47,
      51,    74,    78,    84,     8,    71,    93,    93,    93,    47,
      76,    50,    51,    69,    71,    79,    80,    81,     3,    28,
      27,    20,    21,    22,    23,    24,    25,    26,    14,    15,
      16,    17,    19,    18,     9,    45,    42,     6,    11,    69,
      42,    76,    43,    44,    45,    58,    48,    58,    71,    13,
      62,    63,    70,    67,    69,    69,    48,    70,    71,    40,
      48,    68,    77,    71,    42,    50,    45,    46,    82,    83,
      54,    87,    88,    89,    89,    89,    89,    89,    89,    90,
      91,    91,    92,    92,    92,    94,    70,    69,    71,    71,
      54,    76,    70,    69,    69,    71,    11,    54,     8,    74,
      48,    52,    54,    45,    48,    52,    71,    81,     8,     3,
      45,    54,     8,    40,    54,    42,    54,    71,     8,    71,
       8,     3,    45,    54,    71,     8,     3,    54,     8
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    53,    54,    55,    55,    55,    56,    56,    57,    57,
      57,    58,    58,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    60,    61,    61,    61,
      62,    63,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    67,    68,    68,    69,    70,    70,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    72,    72,    72,
      73,    73,    74,    74,    74,    74,    75,    76,    76,    77,
      77,    77,    78,    78,    79,    80,    80,    81,    81,    81,
      82,    82,    83,    83,    84,    85,    86,    86,    87,    87,
      88,    88,    88,    88,    88,    88,    88,    89,    89,    90,
      90,    90,    91,    91,    91,    91,    92,    92,    92,    92,
      93,    93,    94
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     2,     3,     3,     2,
       2,     1,     0,     3,     1,     3,     5,     4,     4,     9,
      11,     7,     3,     4,     2,     4,     4,     1,     2,     0,
       4,     2,     0,     1,     3,     1,     3,     1,     3,     1,
       4,     3,     1,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     4,     2,     3,     1,     1,     2,     5,     4,     1,
       3,     1,     3,     2,     2,     1,     3,     5,     3,     1,
       1,     1,     1,     0,     1,     1,     3,     1,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     2,     2,     2,     1,
       3,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "DO", "WHILE", "FOR", "UNTIL",
  "REPEAT", "END", "IN", "IF", "THEN", "ELSEIF", "ELSE", "PLUS", "MIN",
  "MUL", "DIV", "POW", "MOD", "EQUAL", "LESS_THAN", "MORE_THAN",
  "LESS_EQUAL_THAN", "MORE_EQUAL_THAN", "TILDE_EQUAL", "CONCAT", "AND",
  "OR", "LEN", "NOT", "LOCAL", "FUNCTION", "RETURN", "BREAK", "NIL",
  "FALSE", "TRUE", "NUMBER", "STRING", "TDOT", "NAME", "ASSIGN", "DOT",
  "COLON", "COMMA", "SEMI", "PARA_L", "PARA_R", "BRACE_L", "BRACE_R",
  "BRACK_L", "BRACK_R", "$accept", "block", "chunk", "optchunk",
  "laststat", "optsemi", "stat", "ifexp", "optelseif", "elseif", "optelse",
  "funcnamelist", "funcname", "varlist", "var", "namelist", "name",
  "explist", "exp", "prefixexp", "functioncall", "args", "function",
  "funcbody", "parlist", "tableconstructor", "fieldlistexp", "fieldlist",
  "field", "fieldsep", "optfieldsep", "string", "ops", "ops_1", "ops_2",
  "ops_3", "ops_4", "ops_5", "ops_6", "ops_7", "ops_8", "ops_9", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,   118,   118,   126,   130,   131,   138,   142,   149,   153,
     154,   158,   159,   163,   168,   169,   173,   178,   183,   189,
     196,   204,   210,   215,   220,   224,   232,   240,   244,   248,
     252,   259,   263,   267,   268,   274,   278,   285,   289,   296,
     297,   302,   309,   313,   320,   324,   328,   335,   336,   337,
     338,   339,   340,   341,   345,   346,   351,   355,   356,   357,
     361,   366,   375,   376,   377,   378,   382,   389,   394,   402,
     406,   410,   414,   418,   422,   429,   433,   441,   446,   451,
     458,   459,   463,   464,   467,   472,   476,   481,   486,   491,
     496,   501,   506,   511,   516,   521,   526,   531,   536,   541,
     546,   551,   556,   561,   566,   571,   576,   580,   584,   588,
     593,   598,   603
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 2037 "binary.tab.cc" // lalr1.cc:1167
