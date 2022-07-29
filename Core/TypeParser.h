/*
 * Copyright (c) 2022 Jon Palmisciano. All rights reserved.
 *
 * Use of this source code is governed by the BSD 3-Clause license; the full
 * terms of the license can be found in the LICENSE.txt file.
 */

#pragma once

#include <string>
#include <vector>
#include <optional>
#include <binaryninjaapi.h>

namespace ObjectiveNinja {

enum ParsedTypeType {
	PredefinedType,
	NamedType,
	StructType
};

struct ParsedType {
	std::string name;
	ParsedTypeType encodedKind;
	std::optional<BinaryNinja::Ref<BinaryNinja::Type>> type;
	std::optional<std::string> dependency;
};

/**
 * Parser for Objective-C type strings.
 */
class TypeParser {
public:
    /**
     * Parse an encoded type string.
     */
    static std::vector<ParsedType> parseEncodedType(BinaryNinja::Ref<BinaryNinja::Architecture> arch, const std::string&);
};

}
