// ==========================================================================
//                 SeqAn - The Library for Sequence Analysis
// ==========================================================================
// Copyright (c) 2006-2012, Knut Reinert, FU Berlin
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of Knut Reinert or the FU Berlin nor the names of
//       its contributors may be used to endorse or promote products derived
//       from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL KNUT REINERT OR THE FU BERLIN BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
// DAMAGE.
//
// ==========================================================================
// Author: Manuel Holtgrewe <manuel.holtgrewe@fu-berlin.de>
// ==========================================================================

#ifndef SEQAN_CORE_INCLUDE_SEQAN_BASIC_AGGREGATE_CONCEPT_H_
#define SEQAN_CORE_INCLUDE_SEQAN_BASIC_AGGREGATE_CONCEPT_H_

namespace seqan {

// TODO(holtgrew): What about empty base class optimization as does Boost's compressed_pair? Not useful?

// ============================================================================
// Forwards
// ============================================================================

// ============================================================================
// Tags, Classes, Enums
// ============================================================================

// ----------------------------------------------------------------------------
// Concept Aggregate
// ----------------------------------------------------------------------------

// Define the concept aggregate and the concept's functions and metafunctions.

/**
.Concept.Aggregate
..summary:Aggregate types contain a fixed number of fixed-size values.
..remarks:Stream output operators are not shown in the function list below, but required.
..remarks:Comparison operators are not shown in the function list below, but required.

.Function.Aggregate#clear
..cat:Aggregates
..concept:Concept.Aggregate
..summary:Clear an aggregate.
..signature:clear(obj)
..param.obj:The aggregate to clear.
..include:seqan/basic.h

.Function.Aggregate#getValue
..cat:Aggregates
..concept:Concept.Aggregate
..summary:Get entry of aggregate by index.
..signature:GetValue getValue(obj, i)
..param.obj:Aggregate to get entry of.
..param.i:Index of entry to assign.
..include:seqan/basic.h

.Function.Aggregate#assignValue
..cat:Aggregates
..concept:Concept.Aggregate
..summary:Get entry of aggregate by index.
..signature:Value assignValue(obj, i, val)
..param.obj:Aggregate to assign entry of.
..param.i:Index of entry to assign.
..param.val:Value to assign into $i$-th entry of $obj$.
...type:Metafunction.Value
..include:seqan/basic.h

.Function.Aggregate#length
..cat:Aggregates
..concept:Concept.Aggregate
..summary:Return length of aggregate.
..description:Since the length of an aggregate is fixed at compile-time, this is equivalent to using @Metafunction.Aggregate#LENGTH@ on the aggregate type.
..signature:length(obj)
..param.obj:The aggregate to get the length of.
..include:seqan/basic.h

.Metafunction.Aggregate#GetValue
..cat:Aggregates
..concept:Concept.Aggregate
..summary:Get type for fast reading of an aggregate's values.
..signature:GetValue<TAggregate[, INDEX]>::Type
..param.TAggregate:The Aggregate type to query.
..param.INDEX:The index of the aggregate to retrieve the type for.
...default:$0$
...type:nolink:$unsigned$
..remarks:
The argument $INDEX$ is 1-based and optional, the default value is $0$.
For tuples, giving an $INDEX$ does not make sense and the type of the contained elements is used.
..returns:Returns the type for fast reading of an aggregate's value at position $INDEX$.
..see:Metafunction.Aggregate#Value
..include:seqan/basic.h

.Metafunction.Aggregate#LENGTH
..cat:Aggregates
..concept:Concept.Aggregate
..summary:Return the number of entries in the aggregate.
..signature:LENGTH<TAggregate>::VALUE
..param.TAggregate:The Aggregate type to query.
..returns:Returns the number of entries in the aggregate.
..include:seqan/basic.h

.Metafunction.Aggregate#Position
..cat:Aggregates
..concept:Concept.Aggregate
..summary:Returns the position type for the aggregate.
..signature:Position<TAggregate>::Type
..param.TAggregate:The Aggregate type to query.
..returns:Returns the type that is sufficient for storing positions in the aggregate.
..include:seqan/basic.h

.Metafunction.Aggregate#Size
..cat:Aggregates
..concept:Concept.Aggregate
..summary:Returns the size type for the aggregate.
..signature:Size<TAggregate>::Type
..param.TAggregate:The Aggregate type to query.
..returns:Returns the type that is sufficient for storing lengths of the aggregate.
..include:seqan/basic.h

.Metafunction.Aggregate#Spec
..cat:Aggregates
..concept:Concept.Aggregate
..summary:Return the specialization of the aggregate type.
..signature:Spec<TAggregate>::Type
..param.TAggregate:The Aggregate type to query.
..returns:Returns the specialization of the aggregate type.
..include:seqan/basic.h

.Metafunction.Aggregate#Value
..cat:Aggregates
..concept:Concept.Aggregate
..summary:Return the type of the aggregate elements.
..signature:Spec<TAggregate[, INDEX]>::Type
..param.TAggregate:The Aggregate type to query.
..param.INDEX:The index of the aggregate to retrieve the type for.
...default:$0$
...type:nolink:$unsigned$
..remarks:
The argument $INDEX$ is 1-based and optional, the default value is $0$.
For tuples, giving an $INDEX$ does not make sense and the type of the contained elements is used.
..returns:Returns the type of the element stored in $TAggregate$ aggregates at position $INDEX$.
..see:Metafunction.Aggregate#GetValue
..include:seqan/basic.h
*/

// TOOD(holtgrew): Necessary?
/**
.Tag.Compressed
..cat:Aggregates
..summary:Tag to marke a "compressed" specialization.
..signature:Compressed
..include:seqan/basic.h
 */

struct Compressed_;
typedef Tag<Compressed_> Compressed;

// TOOD(holtgrew): Necessary?
/**
.Tag.BitCompressed
..cat:Aggregates
..summary:Tag to marke a "compressed" specialization.
..signature:Compressed<BITSIZE1, BITSIZE2>
..param.BITSIZE1:Number of bits used for first element.
...type:nolink:$unsigned$
..param.BITSIZE2:Number of bits used for second element.
...type:nolink:$unsigned$
..include:seqan/basic.h
 */

template <unsigned BITSIZE1 = 16, unsigned BITSIZE2 = 16>
struct BitCompressed;

// ============================================================================
// Metafunctions
// ============================================================================

// ============================================================================
// Functions
// ============================================================================

}  // namespace seqan

#endif  // #ifndef SEQAN_CORE_INCLUDE_SEQAN_BASIC_AGGREGATE_CONCEPT_H_
