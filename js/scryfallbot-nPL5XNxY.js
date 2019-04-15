let messages = [
    '/card lightning bolt',
    '/card -s lightning',
    '/card -i lightning',
    '/card -r lightning',
    '/card -h',
    '/card -v',
    '/card --search lightning',
    '/card --info lightning bolt',
    '/card --rulings lightning bolt',
    '/card --help',
    '/card --version'
];

let strip_card = (message) => message.replace('/card', '').trim();

let strip_command = (message, command) => message.replace(command, '').trim();

let command_parser = (message) => {
    let commands = {
        SEARCH: {
            aliases: ['--search', '-s']
        },
        INFO: {
            aliases: ['--info', '-i']
        },
        RULINGS: {
            aliases: ['--rulings', '-r']
        },
        HELP: {
            aliases: ['--help', '-h']
        },
        VERSION: {
            aliases: ['--version', '-v']
        }
    };
    
    let response_command = 'STANDARD';
    for (let cmd in commands) {
        if (commands[cmd].aliases.some(a => message.startsWith(a))) {
            response_command = cmd;
        }
    }

    if (command_parser.hasOwnProperty(response_command)) {
        commands[response_command].aliases.forEach(alias => message = message.replace(alias, ''));
    }

    if (response_command != 'STANDARD'){
        commands[response_command].aliases.forEach(alias => message = strip_command(message, alias));
    }

    return [response_command, message];
};

class ScryfallBot {
    NamedSearch(query) {
        let url = 'https://api.scryfall.com/cards/named?fuzzy=' + encodeURI(query)

        return url;
    }

    StandardSearch(query) {
        let url = 'https://api.scryfall.com/cards/search?q=' + encodeURI(query) + '&include_extras=true';

        return url;
    }

    RulingsSearch(query) {
        let url = 'https://api.scryfall.com/cards/search?q=' + encodeURI(query) + '&include_extras=true';

        return 'RESPONSE FROM STANDARD SEARCH -> GET RULINGS LINK -> PARSE LINK FOR RULINGS';
    }
}

// Responses include a .object property of type { list, card, ? }

class ScryfallCardObject {
    construct(json) {
        this.name = json.name;
        this.image_uris = json.image_uris;
            // Object:
            //  .small
            //  .normal (average use case)
            //  .large
            //  .png
            //  .art_crop (just art)
            //  .border_crop (no border?)
        this.cmc = json.cmc;
        this.type = json.type_line;
        this.oracle = json.oracle_text;
        this.manaCost = json.mana_cost;
        this.colors = json.colors; // []
        this.color_identity = json.color_identity; // []
        this.legalities = json.legalities;
            // Object:
            // standard, frontier, modern
            // pauper, legacy, penny
            // vintage, duel commander
            // 1v1, future
        this.set = json.set;
        this.set_name = json.set_name;
        this.rulings = json.rulings_uri;
        this.rarity = json.rarity;
        this.artist = json.artist;
        this.tcgMid = json.usd;
        this.mtgo = json.tix; // Optionally not there
        this.gatherer = json.related_uris.gatherer;
        this.tcgPlayer = json.purchase_uris.tcgplayer;
        this.mtgoTraders = json.purchase_uris.mtgo_traders;
    }
}


messages.forEach(m => {
    let bot = new ScryfallBot();
    let queryString = strip_card(m);
    let [command, search] = command_parser(queryString);

    console.log(`Query String: ${queryString}`);
    console.log(`Command:      ${command}`);
    console.log(`Search Query: ${search}`);

    switch (command) {
        case 'SEARCH': 
            console.log(`Searching for all cards matching "${search}"`);
            console.log(bot.StandardSearch(search));
            break;
        case 'INFO': 
            console.log(`Getting information about card "${search}"`);
            console.log(bot.StandardSearch(search));
            break;
        case 'RULINGS': 
            console.log(`Getting ruling information about card "${search}"`)
            console.log(bot.RulingsSearch(search));
            break;
        case 'HELP': 
            console.log('Help Information');
            console.log('/card CARD_NAME                -> Searches for the specified card');
            console.log('/card -s|--search SEARCH_QUERY -> Searches for all cards matching the search query');
            console.log('/card -i|--info CARD_NAME      -> Returns card information about the specified card');
            console.log('/card -r|--rulings CARD_NAME   -> Returns the rulings about the specified card');
            console.log('/card -h|--help                -> Prints this help documentation');
            console.log('/card -v|--version             -> Prints the current version information')
            break;
        case 'VERSION': 
            console.log('Version: 1.0');
            break;
        default: 
            console.log(bot.NamedSearch(search));
            break;
    }

    console.log("");
});