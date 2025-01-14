project 'Test'
    kind 'ConsoleApp'
    language 'C++'
    uuid(os.uuid('Test'))
    location(solution().location)

    files '*.cpp'

    includedirs {
        'googletest/googletest/include',
        'googletest/googlemock/include',
        '..',
        '../../spasm/src',
        '../../spasm/src/asm',
    }
    links {
        'sprt',
        'spasm_lib',
        'JSLib',
        'gtest',
        'gmock',
        'gtest_main',
    }
    configuration 'Linux'
        links 'pthread'
    configuration '*'

group 'gtest'
    project 'gtest'
        kind 'StaticLib'
        language 'C++'
        uuid(os.uuid('gtest'))
        location(solution().location)
        files 'googletest/googletest/src/gtest-all.cc'
        files 'googletest/googletest/include/gtest/*.h'
        includedirs {
            'googletest/googletest',
            'googletest/googletest/include',
        }

    project 'gmock'
        kind 'StaticLib'
        language 'C++'
        uuid(os.uuid('gmock'))
        location(solution().location)
        files 'googletest/googlemock/src/gmock-all.cc'
        files 'googletest/googlemock/include/gmock/*.h'
        includedirs {
            'googletest/googlemock',
            'googletest/googlemock/include',
            'googletest/googletest/include',
        }

    project 'gtest_main'
        kind 'StaticLib'
        language 'C++'
        uuid(os.uuid('gtest_main'))
        location(solution().location)
        files 'googletest/googletest/src/gtest_main.cc'
        includedirs {
            'googletest/googletest',
            'googletest/googletest/include',
        }
