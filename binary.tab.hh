// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton interface for Bison LALR(1) parsers in C++

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

/**
 ** \file binary.tab.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_BINARY_TAB_HH_INCLUDED
# define YY_YY_BINARY_TAB_HH_INCLUDED
// //                    "%code requires" blocks.
#line 5 "binary.yy" // lalr1.cc:377

	#include "node.hh"

#line 48 "binary.tab.hh" // lalr1.cc:377


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>
# include "stack.hh"


#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif


namespace yy {
#line 125 "binary.tab.hh" // lalr1.cc:377



  /// A char[S] buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current state.
  template <size_t S>
  struct variant
  {
    /// Type of *this.
    typedef variant<S> self_type;

    /// Empty construction.
    variant ()
    {}

    /// Construct and fill.
    template <typename T>
    variant (const T& t)
    {
      YYASSERT (sizeof (T) <= S);
      new (yyas_<T> ()) T (t);
    }

    /// Destruction, allowed only if empty.
    ~variant ()
    {}

    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    build ()
    {
      return *new (yyas_<T> ()) T;
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    build (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as ()
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a other, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsability.
    /// Swapping between built and (possibly) non-built is done with
    /// variant::move ().
    template <typename T>
    void
    swap (self_type& other)
    {
      std::swap (as<T> (), other.as<T> ());
    }

    /// Move the content of \a other to this.
    ///
    /// Destroys \a other.
    template <typename T>
    void
    move (self_type& other)
    {
      build<T> ();
      swap<T> (other);
      other.destroy<T> ();
    }

    /// Copy the content of \a other to this.
    template <typename T>
    void
    copy (const self_type& other)
    {
      build<T> (other.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
    /// Prohibit blind copies.
    self_type& operator=(const self_type&);
    variant (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ ()
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[S];
    } yybuffer_;
  };


  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // block
      // chunk
      // optchunk
      // laststat
      // optsemi
      // stat
      // ifexp
      // optelseif
      // elseif
      // optelse
      // funcnamelist
      // funcname
      // varlist
      // var
      // namelist
      // name
      // explist
      // exp
      // prefixexp
      // functioncall
      // args
      // function
      // funcbody
      // parlist
      // tableconstructor
      // fieldlistexp
      // fieldlist
      // field
      // fieldsep
      // optfieldsep
      // string
      // ops
      // ops_1
      // ops_2
      // ops_3
      // ops_4
      // ops_5
      // ops_6
      // ops_7
      // ops_8
      // ops_9
      char dummy1[sizeof(Node)];

      // DO
      // WHILE
      // FOR
      // UNTIL
      // REPEAT
      // END
      // IN
      // IF
      // THEN
      // ELSEIF
      // ELSE
      // PLUS
      // MIN
      // MUL
      // DIV
      // POW
      // MOD
      // EQUAL
      // LESS_THAN
      // MORE_THAN
      // LESS_EQUAL_THAN
      // MORE_EQUAL_THAN
      // TILDE_EQUAL
      // CONCAT
      // AND
      // OR
      // LEN
      // NOT
      // LOCAL
      // FUNCTION
      // RETURN
      // BREAK
      // NIL
      // FALSE
      // TRUE
      // NUMBER
      // STRING
      // TDOT
      // NAME
      // ASSIGN
      // DOT
      // COLON
      // COMMA
      // SEMI
      // PARA_L
      // PARA_R
      // BRACE_L
      // BRACE_R
      // BRACK_L
      // BRACK_R
      char dummy2[sizeof(std::string)];
};

    /// Symbol semantic values.
    typedef variant<sizeof(union_type)> semantic_type;
#else
    typedef YYSTYPE semantic_type;
#endif

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m);
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        QUIT = 0,
        DO = 258,
        WHILE = 259,
        FOR = 260,
        UNTIL = 261,
        REPEAT = 262,
        END = 263,
        IN = 264,
        IF = 265,
        THEN = 266,
        ELSEIF = 267,
        ELSE = 268,
        PLUS = 269,
        MIN = 270,
        MUL = 271,
        DIV = 272,
        POW = 273,
        MOD = 274,
        EQUAL = 275,
        LESS_THAN = 276,
        MORE_THAN = 277,
        LESS_EQUAL_THAN = 278,
        MORE_EQUAL_THAN = 279,
        TILDE_EQUAL = 280,
        CONCAT = 281,
        AND = 282,
        OR = 283,
        LEN = 284,
        NOT = 285,
        LOCAL = 286,
        FUNCTION = 287,
        RETURN = 288,
        BREAK = 289,
        NIL = 290,
        FALSE = 291,
        TRUE = 292,
        NUMBER = 293,
        STRING = 294,
        TDOT = 295,
        NAME = 296,
        ASSIGN = 297,
        DOT = 298,
        COLON = 299,
        COMMA = 300,
        SEMI = 301,
        PARA_L = 302,
        PARA_R = 303,
        BRACE_L = 304,
        BRACE_R = 305,
        BRACK_L = 306,
        BRACK_R = 307
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols, and symbols from each type.

  basic_symbol (typename Base::kind_type t);

  basic_symbol (typename Base::kind_type t, const Node v);

  basic_symbol (typename Base::kind_type t, const std::string v);


      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v);

      /// Destroy the symbol.
      ~basic_symbol ();

      /// Destroy contents, and record that is empty.
      void clear ();

      /// Whether empty.
      bool empty () const;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;

    // Symbol constructors declarations.
    static inline
    symbol_type
    make_QUIT ();

    static inline
    symbol_type
    make_DO (const std::string& v);

    static inline
    symbol_type
    make_WHILE (const std::string& v);

    static inline
    symbol_type
    make_FOR (const std::string& v);

    static inline
    symbol_type
    make_UNTIL (const std::string& v);

    static inline
    symbol_type
    make_REPEAT (const std::string& v);

    static inline
    symbol_type
    make_END (const std::string& v);

    static inline
    symbol_type
    make_IN (const std::string& v);

    static inline
    symbol_type
    make_IF (const std::string& v);

    static inline
    symbol_type
    make_THEN (const std::string& v);

    static inline
    symbol_type
    make_ELSEIF (const std::string& v);

    static inline
    symbol_type
    make_ELSE (const std::string& v);

    static inline
    symbol_type
    make_PLUS (const std::string& v);

    static inline
    symbol_type
    make_MIN (const std::string& v);

    static inline
    symbol_type
    make_MUL (const std::string& v);

    static inline
    symbol_type
    make_DIV (const std::string& v);

    static inline
    symbol_type
    make_POW (const std::string& v);

    static inline
    symbol_type
    make_MOD (const std::string& v);

    static inline
    symbol_type
    make_EQUAL (const std::string& v);

    static inline
    symbol_type
    make_LESS_THAN (const std::string& v);

    static inline
    symbol_type
    make_MORE_THAN (const std::string& v);

    static inline
    symbol_type
    make_LESS_EQUAL_THAN (const std::string& v);

    static inline
    symbol_type
    make_MORE_EQUAL_THAN (const std::string& v);

    static inline
    symbol_type
    make_TILDE_EQUAL (const std::string& v);

    static inline
    symbol_type
    make_CONCAT (const std::string& v);

    static inline
    symbol_type
    make_AND (const std::string& v);

    static inline
    symbol_type
    make_OR (const std::string& v);

    static inline
    symbol_type
    make_LEN (const std::string& v);

    static inline
    symbol_type
    make_NOT (const std::string& v);

    static inline
    symbol_type
    make_LOCAL (const std::string& v);

    static inline
    symbol_type
    make_FUNCTION (const std::string& v);

    static inline
    symbol_type
    make_RETURN (const std::string& v);

    static inline
    symbol_type
    make_BREAK (const std::string& v);

    static inline
    symbol_type
    make_NIL (const std::string& v);

    static inline
    symbol_type
    make_FALSE (const std::string& v);

    static inline
    symbol_type
    make_TRUE (const std::string& v);

    static inline
    symbol_type
    make_NUMBER (const std::string& v);

    static inline
    symbol_type
    make_STRING (const std::string& v);

    static inline
    symbol_type
    make_TDOT (const std::string& v);

    static inline
    symbol_type
    make_NAME (const std::string& v);

    static inline
    symbol_type
    make_ASSIGN (const std::string& v);

    static inline
    symbol_type
    make_DOT (const std::string& v);

    static inline
    symbol_type
    make_COLON (const std::string& v);

    static inline
    symbol_type
    make_COMMA (const std::string& v);

    static inline
    symbol_type
    make_SEMI (const std::string& v);

    static inline
    symbol_type
    make_PARA_L (const std::string& v);

    static inline
    symbol_type
    make_PARA_R (const std::string& v);

    static inline
    symbol_type
    make_BRACE_L (const std::string& v);

    static inline
    symbol_type
    make_BRACE_R (const std::string& v);

    static inline
    symbol_type
    make_BRACK_L (const std::string& v);

    static inline
    symbol_type
    make_BRACK_R (const std::string& v);


    /// Build a parser object.
    parser ();
    virtual ~parser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
    parser (const parser&);
    parser& operator= (const parser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short int yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short int yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short int yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short int yytable_[];

  static const short int yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


#if YYDEBUG
    /// For a symbol, its name in clear.
    static const char* const yytname_[];

  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short int yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 391,     ///< Last index in yytable_.
      yynnts_ = 42,  ///< Number of nonterminal symbols.
      yyfinal_ = 68, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 53  ///< Number of tokens.
    };


  };

  // Symbol number corresponding to token number t.
  inline
  parser::token_number_type
  parser::yytranslate_ (token_type t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
    };
    const unsigned int user_token_number_max_ = 307;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  inline
  parser::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
  {
      switch (other.type_get ())
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
        value.copy< Node > (other.value);
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
        value.copy< std::string > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value ()
  {
    (void) v;
      switch (this->type_get ())
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
        value.copy< Node > (v);
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
        value.copy< std::string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Node v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v)
    : Base (t)
    , value (v)
  {}


  template <typename Base>
  inline
  parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
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
        value.template destroy< Node > ();
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
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
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
        value.move< Node > (s.value);
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
        value.move< std::string > (s.value);
        break;

      default:
        break;
    }

  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const
  {
    return type;
  }

  inline
  parser::token_type
  parser::by_type::token () const
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short int
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
    };
    return static_cast<token_type> (yytoken_number_[type]);
  }
  // Implementation of make_symbol for each symbol type.
  parser::symbol_type
  parser::make_QUIT ()
  {
    return symbol_type (token::QUIT);
  }

  parser::symbol_type
  parser::make_DO (const std::string& v)
  {
    return symbol_type (token::DO, v);
  }

  parser::symbol_type
  parser::make_WHILE (const std::string& v)
  {
    return symbol_type (token::WHILE, v);
  }

  parser::symbol_type
  parser::make_FOR (const std::string& v)
  {
    return symbol_type (token::FOR, v);
  }

  parser::symbol_type
  parser::make_UNTIL (const std::string& v)
  {
    return symbol_type (token::UNTIL, v);
  }

  parser::symbol_type
  parser::make_REPEAT (const std::string& v)
  {
    return symbol_type (token::REPEAT, v);
  }

  parser::symbol_type
  parser::make_END (const std::string& v)
  {
    return symbol_type (token::END, v);
  }

  parser::symbol_type
  parser::make_IN (const std::string& v)
  {
    return symbol_type (token::IN, v);
  }

  parser::symbol_type
  parser::make_IF (const std::string& v)
  {
    return symbol_type (token::IF, v);
  }

  parser::symbol_type
  parser::make_THEN (const std::string& v)
  {
    return symbol_type (token::THEN, v);
  }

  parser::symbol_type
  parser::make_ELSEIF (const std::string& v)
  {
    return symbol_type (token::ELSEIF, v);
  }

  parser::symbol_type
  parser::make_ELSE (const std::string& v)
  {
    return symbol_type (token::ELSE, v);
  }

  parser::symbol_type
  parser::make_PLUS (const std::string& v)
  {
    return symbol_type (token::PLUS, v);
  }

  parser::symbol_type
  parser::make_MIN (const std::string& v)
  {
    return symbol_type (token::MIN, v);
  }

  parser::symbol_type
  parser::make_MUL (const std::string& v)
  {
    return symbol_type (token::MUL, v);
  }

  parser::symbol_type
  parser::make_DIV (const std::string& v)
  {
    return symbol_type (token::DIV, v);
  }

  parser::symbol_type
  parser::make_POW (const std::string& v)
  {
    return symbol_type (token::POW, v);
  }

  parser::symbol_type
  parser::make_MOD (const std::string& v)
  {
    return symbol_type (token::MOD, v);
  }

  parser::symbol_type
  parser::make_EQUAL (const std::string& v)
  {
    return symbol_type (token::EQUAL, v);
  }

  parser::symbol_type
  parser::make_LESS_THAN (const std::string& v)
  {
    return symbol_type (token::LESS_THAN, v);
  }

  parser::symbol_type
  parser::make_MORE_THAN (const std::string& v)
  {
    return symbol_type (token::MORE_THAN, v);
  }

  parser::symbol_type
  parser::make_LESS_EQUAL_THAN (const std::string& v)
  {
    return symbol_type (token::LESS_EQUAL_THAN, v);
  }

  parser::symbol_type
  parser::make_MORE_EQUAL_THAN (const std::string& v)
  {
    return symbol_type (token::MORE_EQUAL_THAN, v);
  }

  parser::symbol_type
  parser::make_TILDE_EQUAL (const std::string& v)
  {
    return symbol_type (token::TILDE_EQUAL, v);
  }

  parser::symbol_type
  parser::make_CONCAT (const std::string& v)
  {
    return symbol_type (token::CONCAT, v);
  }

  parser::symbol_type
  parser::make_AND (const std::string& v)
  {
    return symbol_type (token::AND, v);
  }

  parser::symbol_type
  parser::make_OR (const std::string& v)
  {
    return symbol_type (token::OR, v);
  }

  parser::symbol_type
  parser::make_LEN (const std::string& v)
  {
    return symbol_type (token::LEN, v);
  }

  parser::symbol_type
  parser::make_NOT (const std::string& v)
  {
    return symbol_type (token::NOT, v);
  }

  parser::symbol_type
  parser::make_LOCAL (const std::string& v)
  {
    return symbol_type (token::LOCAL, v);
  }

  parser::symbol_type
  parser::make_FUNCTION (const std::string& v)
  {
    return symbol_type (token::FUNCTION, v);
  }

  parser::symbol_type
  parser::make_RETURN (const std::string& v)
  {
    return symbol_type (token::RETURN, v);
  }

  parser::symbol_type
  parser::make_BREAK (const std::string& v)
  {
    return symbol_type (token::BREAK, v);
  }

  parser::symbol_type
  parser::make_NIL (const std::string& v)
  {
    return symbol_type (token::NIL, v);
  }

  parser::symbol_type
  parser::make_FALSE (const std::string& v)
  {
    return symbol_type (token::FALSE, v);
  }

  parser::symbol_type
  parser::make_TRUE (const std::string& v)
  {
    return symbol_type (token::TRUE, v);
  }

  parser::symbol_type
  parser::make_NUMBER (const std::string& v)
  {
    return symbol_type (token::NUMBER, v);
  }

  parser::symbol_type
  parser::make_STRING (const std::string& v)
  {
    return symbol_type (token::STRING, v);
  }

  parser::symbol_type
  parser::make_TDOT (const std::string& v)
  {
    return symbol_type (token::TDOT, v);
  }

  parser::symbol_type
  parser::make_NAME (const std::string& v)
  {
    return symbol_type (token::NAME, v);
  }

  parser::symbol_type
  parser::make_ASSIGN (const std::string& v)
  {
    return symbol_type (token::ASSIGN, v);
  }

  parser::symbol_type
  parser::make_DOT (const std::string& v)
  {
    return symbol_type (token::DOT, v);
  }

  parser::symbol_type
  parser::make_COLON (const std::string& v)
  {
    return symbol_type (token::COLON, v);
  }

  parser::symbol_type
  parser::make_COMMA (const std::string& v)
  {
    return symbol_type (token::COMMA, v);
  }

  parser::symbol_type
  parser::make_SEMI (const std::string& v)
  {
    return symbol_type (token::SEMI, v);
  }

  parser::symbol_type
  parser::make_PARA_L (const std::string& v)
  {
    return symbol_type (token::PARA_L, v);
  }

  parser::symbol_type
  parser::make_PARA_R (const std::string& v)
  {
    return symbol_type (token::PARA_R, v);
  }

  parser::symbol_type
  parser::make_BRACE_L (const std::string& v)
  {
    return symbol_type (token::BRACE_L, v);
  }

  parser::symbol_type
  parser::make_BRACE_R (const std::string& v)
  {
    return symbol_type (token::BRACE_R, v);
  }

  parser::symbol_type
  parser::make_BRACK_L (const std::string& v)
  {
    return symbol_type (token::BRACK_L, v);
  }

  parser::symbol_type
  parser::make_BRACK_R (const std::string& v)
  {
    return symbol_type (token::BRACK_R, v);
  }



} // yy
#line 1880 "binary.tab.hh" // lalr1.cc:377




#endif // !YY_YY_BINARY_TAB_HH_INCLUDED
