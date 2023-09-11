package json.core;

import base.core.ArrayLists;
import base.core.Pair;
import base.interfaces.IPair;
import json.interfaces.ITestData;
import testbase.core.ResourcePaths;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

/**
 * The TestData class implements the data of the tests.
 */
public final class TestData implements ITestData {
    private static final String DATA_DIRECTORY_NAME = "data";
    private static final String JSON_DIRECTORY_NAME = "json";

    private static final List<IPair<String, Class<?>>> jsonResourcesInformation = ArrayLists.make(
        Pair.make("propertyType.json", PropertyType.class),
        Pair.make("fruit.json", Fruit.class),
        Pair.make("colors.json", Colors.class));

    /**
     * The TestData constructor.
     */
    public TestData() {
    }

    /**
     * Gets information of json resources.
     */
    @Override
    public List<IPair<Path, Class<?>>> getJsonResourcesInformation() {
        List<IPair<Path, Class<?>>> information = new ArrayList<>();

        for (IPair<String, Class<?>> resourceInformation : jsonResourcesInformation) {
            Path path = ResourcePaths.create(
                DATA_DIRECTORY_NAME,
                JSON_DIRECTORY_NAME,
                resourceInformation.first());

            Class<?> classType = resourceInformation.second();

            information.add(Pair.make(path, classType));
        }

        return information;
    }

}
